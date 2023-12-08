<?php

namespace App\Controller;

use App\Entity\Command;
use App\Entity\Product;
use App\Entity\Restaurant;
use App\Form\CommandType;
use App\Form\ProductType;
use App\Form\RestaurantType;
use App\Repository\CommandRepository;
use App\Repository\RestaurantRepository;
use Doctrine\ORM\EntityManagerInterface;
use Symfony\Bridge\Doctrine\Attribute\MapEntity;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;

#[Route('/restaurant')]
class RestaurantController extends AbstractController
{
    #[Route('/', name: 'app_restaurant_index', methods: ['GET'])]
    public function index(RestaurantRepository $restaurantRepository): Response
    {
        return $this->render('restaurant/index.html.twig', [
            'restaurants' => $restaurantRepository->findAll(),
        ]);
    }

    #[Route('/new', name: 'app_restaurant_new', methods: ['GET', 'POST'])]
    public function new(Request $request, EntityManagerInterface $entityManager): Response
    {
        $restaurant = new Restaurant();
        $form = $this->createForm(RestaurantType::class, $restaurant);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->persist($restaurant);
            $entityManager->flush();

            return $this->redirectToRoute('app_restaurant_index', [], Response::HTTP_SEE_OTHER);
        }

        return $this->render('restaurant/new.html.twig', [
            'restaurant' => $restaurant,
            'form' => $form,
        ]);
    }

    #[Route('/new/product/{id}', name: 'app_product_new', methods: ['GET', 'POST'])]
    public function newProduct(Request $request, EntityManagerInterface $entityManager, Restaurant $restaurant): Response
    {
        $product = new Product();
        $product->setRestaurant($restaurant);
        $form = $this->createForm(ProductType::class, $product);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->persist($product);
            $entityManager->flush();

            return $this->redirectToRoute('app_restaurant_show', ['id' => $restaurant->getId()], Response::HTTP_SEE_OTHER);
        }

        return $this->render('restaurant/new_product.html.twig', [
            'product' => $product,
            'restaurant' => $restaurant,
            'form' => $form,
        ]);
    }

    #[Route('/new/command/{id}', name: 'app_command_new', methods: ['GET', 'POST'])]
    public function newCommand(Request $request, Restaurant $restaurant, EntityManagerInterface $entityManager): Response
    {
        $command = new Command();
        $form = $this->createForm(CommandType::class, $command, [
            'restaurant' => $restaurant,
        ]);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $command->applyTotalAmount();
            $entityManager->persist($command);
            $entityManager->flush();

            return $this->redirectToRoute('app_restaurant_show', ['id' => $restaurant->getId()], Response::HTTP_SEE_OTHER);
        }

        return $this->render('command/new.html.twig', [
            'command' => $command,
            'restaurant' => $restaurant,
            'form' => $form,
        ]);
    }

    #[Route('/{id}', name: 'app_restaurant_show', methods: ['GET'])]
    public function show(Restaurant $restaurant, CommandRepository $commandRepository): Response
    {
        $sales = $commandRepository->getSales($restaurant);
        $restaurantCommands = $commandRepository->findCommandsByRestaurant($restaurant);
        $restaurantCommandsCount = count($restaurantCommands);

        return $this->render('restaurant/show.html.twig', [
            'restaurant' => $restaurant,
            'sales' => $sales,
            'commandsCount' => $restaurantCommandsCount,
        ]);
    }

    #[Route('/{id}/product/{id2}', name: 'app_product_show', methods: ['GET'])]
    public function showProduct(#[MapEntity(id: 'id')] Restaurant $restaurant, #[MapEntity(id: 'id2')] Product $product): Response
    {
        return $this->render('restaurant/show_product.html.twig', [
            'product' => $product,
            'restaurant' => $restaurant,
        ]);
    }

    #[Route('/{id}/edit', name: 'app_restaurant_edit', methods: ['GET', 'POST'])]
    public function edit(Request $request, Restaurant $restaurant, EntityManagerInterface $entityManager): Response
    {
        $form = $this->createForm(RestaurantType::class, $restaurant);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->flush();

            return $this->redirectToRoute('app_restaurant_index', [], Response::HTTP_SEE_OTHER);
        }

        return $this->render('restaurant/edit.html.twig', [
            'restaurant' => $restaurant,
            'form' => $form,
        ]);
    }

    #[Route('/{id}/edit/product/{id2}', name: 'app_product_edit', methods: ['GET', 'POST'])]
    public function editProduct(Request $request, #[MapEntity(id: 'id')] Restaurant $restaurant, #[MapEntity(id: 'id2')] Product $product, EntityManagerInterface $entityManager): Response
    {
        $form = $this->createForm(ProductType::class, $product);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->flush();

            return $this->redirectToRoute('app_restaurant_show', ['id' => $restaurant->getId()], Response::HTTP_SEE_OTHER);
        }

        return $this->render('restaurant/edit_product.html.twig', [
            'product' => $product,
            'restaurant' => $restaurant,
            'form' => $form,
        ]);
    }

    #[Route('/{id}', name: 'app_restaurant_delete', methods: ['POST'])]
    public function delete(Request $request, Restaurant $restaurant, EntityManagerInterface $entityManager): Response
    {
        if ($this->isCsrfTokenValid('delete' . $restaurant->getId(), $request->request->get('_token'))) {
            $entityManager->remove($restaurant);
            $entityManager->flush();
        }

        return $this->redirectToRoute('app_restaurant_index', [], Response::HTTP_SEE_OTHER);
    }

    #[Route('/{id}/product/{id2}', name: 'app_product_delete', methods: ['POST'])]
    public function deleteProduct(Request $request, #[MapEntity(id: 'id')] Restaurant $restaurant, #[MapEntity(id: 'id2')] Product $product, EntityManagerInterface $entityManager): Response
    {
        if ($this->isCsrfTokenValid('delete' . $product->getId(), $request->request->get('_token'))) {
            $entityManager->remove($product);
            $entityManager->flush();
        }

        return $this->redirectToRoute('app_restaurant_show', ['id' => $restaurant->getId()], Response::HTTP_SEE_OTHER);
    }
}
