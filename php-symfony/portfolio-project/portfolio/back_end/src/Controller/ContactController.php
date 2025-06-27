<?php

namespace App\Controller;

use App\Entity\Message;
use Doctrine\ORM\EntityManagerInterface;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\Routing\Annotation\Route;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\Validator\Validator\ValidatorInterface;

class ContactController extends AbstractController
{
    #[Route('/contact', name: 'api_contact', methods: ['POST'])]
    public function contact(Request $request, EntityManagerInterface $em, ValidatorInterface $validator)
    {
        $data = json_decode($request->getContent(), true);

        $message = new Message();
        $message->setName($data['name'] ?? '');
        $message->setEmail($data['email'] ?? '');
        $message->setMessage($data['message'] ?? '');
        $message->setCreatedAt(new \DateTime('now'));

        $errors = $validator->validate($message);

        if (count($errors) > 0) {
            return $this->json(['errors' => $errors], 400);
        }

        $em->persist($message);
        $em->flush();

        return $this->json(['status' => 'Message enregistré'], 200);
    }

    #[Route('/messages', name: 'api_messages', methods: ['GET'])]
    public function getMessages(EntityManagerInterface $em)
    {
        $messages = $em->getRepository(Message::class)->findBy([], ['createdAt' => 'DESC']);

        $data = array_map(fn(Message $msg) => [
            'id' => $msg->getId(),
            'name' => $msg->getName(),
            'email' => $msg->getEmail(),
            'message' => $msg->getMessage(),
            'createdAt' => $msg->getCreatedAt()->format('c') // génère une date au fomrat ISO 8601 lisible par Javascript
        ], $messages);

        return $this->json($data);
    }
}
