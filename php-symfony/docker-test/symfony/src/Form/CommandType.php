<?php

namespace App\Form;

use App\Entity\Command;
use App\Entity\Person;
use App\Entity\Product;
use Symfony\Bridge\Doctrine\Form\Type\EntityType;
use Symfony\Component\Form\AbstractType;
use Symfony\Component\Form\FormBuilderInterface;
use Symfony\Component\OptionsResolver\OptionsResolver;

class CommandType extends AbstractType
{
    public function buildForm(FormBuilderInterface $builder, array $options): void
    {
        $restaurant = $options['restaurant'];

        $builder
            ->add('owner', EntityType::class, [
                'class' => Person::class,
                'choice_label' => function (Person $person) {
                    return $person->getReadableName();
                }
            ])
            ->add('products', EntityType::class, [
                'class' => Product::class,
                'choices' => $restaurant ? $restaurant->getProducts() : [],
                'multiple' => true,
                'expanded' => false,
                'choice_label' => 'name',
            ])
        ;
    }

    public function configureOptions(OptionsResolver $resolver): void
    {
        $resolver->setDefaults([
            'data_class' => Command::class,
            'restaurant' => null,
        ]);
    }
}
