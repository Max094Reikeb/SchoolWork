<?php

namespace App\Entity;

use App\Repository\CommandRepository;
use Doctrine\Common\Collections\ArrayCollection;
use Doctrine\Common\Collections\Collection;
use Doctrine\ORM\Mapping as ORM;

#[ORM\Entity(repositoryClass: CommandRepository::class)]
class Command
{
    #[ORM\Id]
    #[ORM\GeneratedValue]
    #[ORM\Column]
    private ?int $id = null;

    #[ORM\ManyToMany(targetEntity: Product::class, inversedBy: 'commands')]
    private Collection $products;

    #[ORM\Column]
    private ?int $totalAmount = null;

    #[ORM\ManyToOne(inversedBy: 'commands')]
    #[ORM\JoinColumn(nullable: false)]
    private ?Person $owner = null;

    public function __construct()
    {
        $this->products = new ArrayCollection();
    }

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getProducts(): Collection
    {
        return $this->products;
    }

    public function getRestaurant(): Restaurant
    {
        return $this->products->first()->getRestaurant();
    }

    public function addProduct(Product $product): static
    {
        if (!$this->products->contains($product)) {
            $this->products->add($product);
        }
        return $this;
    }

    public function removeProduct(Product $product): static
    {
        $this->products->removeElement($product);
        return $this;
    }

    public function getTotalAmount(): ?int
    {
        return $this->totalAmount;
    }

    public function setTotalAmount(int $totalAmount): static
    {
        $this->totalAmount = $totalAmount;
        return $this;
    }

    public function applyTotalAmount(): static
    {
        $totalAmount = 0;
        foreach ($this->products as $product) {
            $totalAmount += $product->getPrice();
        }
        $this->totalAmount = $totalAmount;
        return $this;
    }

    public function getOwner(): ?Person
    {
        return $this->owner;
    }

    public function setOwner(?Person $owner): static
    {
        $this->owner = $owner;
        return $this;
    }
}
