<?php

namespace App\Form;

use App\Entity\Account;
use App\Entity\Person;
use Symfony\Bridge\Doctrine\Form\Type\EntityType;
use Symfony\Component\Form\AbstractType;
use Symfony\Component\Form\Extension\Core\Type\EnumType;
use Symfony\Component\Form\FormBuilderInterface;
use Symfony\Component\OptionsResolver\OptionsResolver;

class AccountType extends AbstractType
{
    public function buildForm(FormBuilderInterface $builder, array $options): void
    {
        if (!$options['exclude_owner']) {
            $builder->add('owner', EntityType::class, [
                'class' => Person::class,
                'choice_label' => function (Person $person) {
                    return $person->getReadableName();
                }
            ]);
        }

        $builder
            ->add('type', EnumType::class, [
                'class' => \App\Property\AccountType::class,
                'choice_label' => function (\App\Property\AccountType $type) {
                    return $type->value;
                }
            ])
            ->add('iban')
            ->add('balance')
            ->add('minBalance');
    }

    public function configureOptions(OptionsResolver $resolver): void
    {
        $resolver->setDefaults([
            'data_class' => Account::class,
            'exclude_owner' => false,
        ]);
    }
}
