<?php

namespace App\Entity;

use App\Property\AccountType;
use App\Repository\AccountRepository;
use Doctrine\Common\Collections\ArrayCollection;
use Doctrine\Common\Collections\Collection;
use Doctrine\ORM\Mapping as ORM;
use Symfony\Component\Validator\Constraints as Assert;

#[ORM\Entity(repositoryClass: AccountRepository::class)]
class Account
{
    #[ORM\Id]
    #[ORM\GeneratedValue]
    #[ORM\Column]
    private ?int $id = null;

    #[ORM\Column]
    private AccountType $type;

    #[ORM\Column]
    #[Assert\Iban(message: "The IBAN is not valid.")]
    private string $iban;

    #[ORM\Column]
    private ?int $balance = null;

    #[ORM\Column]
    private ?int $minBalance = null;

    #[ORM\OneToMany(mappedBy: 'debitAccount', targetEntity: Transaction::class, orphanRemoval: true)]
    private Collection $debitTransactions;

    #[ORM\OneToMany(mappedBy: 'creditAccount', targetEntity: Transaction::class, orphanRemoval: true)]
    private Collection $creditTransactions;

    #[ORM\ManyToOne(inversedBy: 'accounts')]
    #[ORM\JoinColumn(nullable: false)]
    private ?Person $owner = null;

    public function __construct()
    {
        $this->debitTransactions = new ArrayCollection();
        $this->creditTransactions = new ArrayCollection();
    }

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getType(): AccountType
    {
        return $this->type;
    }

    public function setType(AccountType $type): self
    {
        $this->type = $type;
        return $this;
    }

    public function getIban(): ?string
    {
        return $this->formatIbanForDisplay($this->iban);
    }

    public function setIban(string $iban): self
    {
        $this->iban = $this->cleanIbanInput($iban);
        return $this;
    }

    private function formatIbanForDisplay(?string $iban): ?string
    {
        return wordwrap($iban, 4, ' ', true);
    }

    private function cleanIbanInput(string $iban): string
    {
        return preg_replace('/[^A-Za-z0-9]/', '', $iban);
    }

    public function getBalance(): ?int
    {
        return $this->balance;
    }

    public function getMinBalance(): ?int
    {
        return $this->minBalance;
    }

    public function setBalance(int $balance): static
    {
        $this->balance = $balance;
        return $this;
    }

    public function setMinBalance(int $minBalance): static
    {
        $this->minBalance = $minBalance;
        return $this;
    }

    public function getDebitTransactions(): Collection
    {
        return $this->debitTransactions;
    }

    public function addDebitTransaction(Transaction $debitTransaction): static
    {
        if (!$this->debitTransactions->contains($debitTransaction)) {
            $this->debitTransactions->add($debitTransaction);
            $debitTransaction->setDebitAccount($this);
        }
        return $this;
    }

    public function removeDebitTransaction(Transaction $debitTransaction): static
    {
        if ($this->debitTransactions->removeElement($debitTransaction)) {
            // set the owning side to null (unless already changed)
            if ($debitTransaction->getDebitAccount() === $this) {
                $debitTransaction->setDebitAccount(null);
            }
        }
        return $this;
    }

    public function getCreditTransactions(): Collection
    {
        return $this->creditTransactions;
    }

    public function addCreditTransaction(Transaction $creditTransaction): static
    {
        if (!$this->creditTransactions->contains($creditTransaction)) {
            $this->creditTransactions->add($creditTransaction);
            $creditTransaction->setCreditAccount($this);
        }
        return $this;
    }

    public function removeCreditTransaction(Transaction $creditTransaction): static
    {
        if ($this->creditTransactions->removeElement($creditTransaction)) {
            // set the owning side to null (unless already changed)
            if ($creditTransaction->getCreditAccount() === $this) {
                $creditTransaction->setCreditAccount(null);
            }
        }
        return $this;
    }

    public function getAllTransactions(): Collection
    {
        $allTransactions = new ArrayCollection(
            array_merge($this->debitTransactions->toArray(), $this->creditTransactions->toArray())
        );

        $iterator = $allTransactions->getIterator();
        $iterator->uasort(function ($a, $b) {
            return $a->getDate() <=> $b->getDate();
        });
        return new ArrayCollection(iterator_to_array($iterator));
    }

    public function formatAllTransactionsForDisplay(): string
    {
        $displayTransactions = "";
        foreach ($this->getAllTransactions() as $transaction) {
            if ($displayTransactions != "") {
                $displayTransactions .= "<br>";
            }
            $amount = $transaction->getAmount();
            $date = $transaction->getDate()->format('Y-m-d H:i:s');
            $type = $transaction->getDebitAccount() === $this ? "-" : "+";
            $displayTransactions .= $type . $amount . " (" . $date . ")";
        }
        return $displayTransactions;
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
