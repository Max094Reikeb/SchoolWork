<?php

namespace App\Controller;

use App\Entity\Command;
use App\Entity\Person;
use App\Form\CommandType;
use App\Form\PersonType;
use App\Repository\PersonRepository;
use Doctrine\ORM\EntityManagerInterface;
use Symfony\Bridge\Doctrine\Attribute\MapEntity;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;

#[Route('/person')]
class PersonController extends AbstractController
{
    #[Route('/', name: 'app_person_index', methods: ['GET'])]
    public function index(PersonRepository $personRepository): Response
    {
        return $this->render('person/index.html.twig', [
            'persons' => $personRepository->findAll(),
        ]);
    }

    #[Route('/new', name: 'app_person_new', methods: ['GET', 'POST'])]
    public function new(Request $request, EntityManagerInterface $entityManager): Response
    {
        $person = new Person();
        $form = $this->createForm(PersonType::class, $person);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->persist($person);
            $entityManager->flush();

            return $this->redirectToRoute('app_person_index', [], Response::HTTP_SEE_OTHER);
        }

        return $this->render('person/new.html.twig', [
            'person' => $person,
            'form' => $form,
        ]);
    }

    #[Route('/{id}', name: 'app_person_show', methods: ['GET'])]
    public function show(Person $person): Response
    {
        return $this->render('person/show.html.twig', [
            'person' => $person,
        ]);
    }

    #[Route('/{id}/command/{id2}', name: 'app_command_show', methods: ['GET'])]
    public function showCommand(#[MapEntity(id: 'id')] Person $person, #[MapEntity(id: 'id2')] Command $command): Response
    {
        return $this->render('command/show.html.twig', [
            'person' => $person,
            'command' => $command,
        ]);
    }

    #[Route('/{id}/edit', name: 'app_person_edit', methods: ['GET', 'POST'])]
    public function edit(Request $request, Person $person, EntityManagerInterface $entityManager): Response
    {
        $form = $this->createForm(PersonType::class, $person);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->flush();

            return $this->redirectToRoute('app_person_index', [], Response::HTTP_SEE_OTHER);
        }

        return $this->render('person/edit.html.twig', [
            'person' => $person,
            'form' => $form,
        ]);
    }

    #[Route('/{id}/edit/command/{id2}', name: 'app_command_edit', methods: ['GET', 'POST'])]
    public function editCommand(Request $request, #[MapEntity(id: 'id')] Person $person, #[MapEntity(id: 'id2')] Command $command, EntityManagerInterface $entityManager): Response
    {
        $form = $this->createForm(CommandType::class, $command, [
            'restaurant' => $command->getRestaurant(),
        ]);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $command->applyTotalAmount();
            $entityManager->flush();

            return $this->redirectToRoute('app_person_show', ['id' => $person->getId()], Response::HTTP_SEE_OTHER);
        }

        return $this->render('command/edit.html.twig', [
            'person' => $person,
            'command' => $command,
            'form' => $form,
        ]);
    }

    #[Route('/{id}', name: 'app_person_delete', methods: ['POST'])]
    public function delete(Request $request, Person $person, EntityManagerInterface $entityManager): Response
    {
        if ($this->isCsrfTokenValid('delete' . $person->getId(), $request->request->get('_token'))) {
            $entityManager->remove($person);
            $entityManager->flush();
        }

        return $this->redirectToRoute('app_person_index', [], Response::HTTP_SEE_OTHER);
    }
}
