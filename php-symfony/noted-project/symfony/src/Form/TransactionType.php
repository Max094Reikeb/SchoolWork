<?php

namespace App\Form;

use App\Entity\Account;
use App\Entity\Transaction;
use Symfony\Bridge\Doctrine\Form\Type\EntityType;
use Symfony\Component\Form\AbstractType;
use Symfony\Component\Form\FormBuilderInterface;
use Symfony\Component\Form\FormEvent;
use Symfony\Component\Form\FormEvents;
use Symfony\Component\OptionsResolver\OptionsResolver;

class TransactionType extends AbstractType
{
    public function buildForm(FormBuilderInterface $builder, array $options): void
    {
        $person = $options['person'];
        $builder
            ->add('amount')
            ->add('label')
            ->addEventListener(FormEvents::PRE_SET_DATA, function (FormEvent $event) use ($person) {
                $form = $event->getForm();

                if ($person) {
                    $form->add('debitAccount', EntityType::class, [
                        'class' => Account::class,
                        'choices' => $person->getAccounts(),
                        'choice_label' => function (Account $account) {
                            return $account->getOwner()->getReadableName() . " - " . $account->getIban() . " - " . $account->getType()->value;
                        },
                    ]);
                } else {
                    $form->add('debitAccount', EntityType::class, [
                        'class' => Account::class,
                        'choice_label' => function (Account $account) {
                            return $account->getOwner()->getReadableName() . " - " . $account->getIban() . " - " . $account->getType()->value;
                        },
                    ]);
                }
            })
            ->add('creditAccount', EntityType::class, [
                'class' => Account::class,
                'choice_label' => function (Account $account) {
                    return $account->getOwner()->getReadableName() . " - " . $account->getIban() . " - " . $account->getType()->value;
                },
            ]);
    }

    public function configureOptions(OptionsResolver $resolver): void
    {
        $resolver->setDefaults([
            'data_class' => Transaction::class,
            'person' => null,
        ]);
    }
}
