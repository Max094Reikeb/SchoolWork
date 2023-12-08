<?php

namespace App\Repository;

use App\Entity\Command;
use App\Entity\Restaurant;
use Doctrine\Bundle\DoctrineBundle\Repository\ServiceEntityRepository;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @extends ServiceEntityRepository<Command>
 *
 * @method Command|null find($id, $lockMode = null, $lockVersion = null)
 * @method Command|null findOneBy(array $criteria, array $orderBy = null)
 * @method Command[]    findAll()
 * @method Command[]    findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class CommandRepository extends ServiceEntityRepository
{
    public function __construct(ManagerRegistry $registry)
    {
        parent::__construct($registry, Command::class);
    }

    public function getSales(Restaurant $restaurant): int
    {
        $commands = $this->findCommandsByRestaurant($restaurant);
        $sales = 0;
        foreach ($commands as $command) {
            $sales += $command->getTotalAmount();
        }
        return $sales;
    }

    public function findCommandsByRestaurant(Restaurant $restaurant): array
    {
        return $this->createQueryBuilder('c')
            ->join('c.products', 'p')
            ->andWhere('p.restaurant = :restaurant')
            ->setParameter('restaurant', $restaurant)
            ->getQuery()
            ->getResult();
    }

//    /**
//     * @return Command[] Returns an array of Command objects
//     */
//    public function findByExampleField($value): array
//    {
//        return $this->createQueryBuilder('c')
//            ->andWhere('c.exampleField = :val')
//            ->setParameter('val', $value)
//            ->orderBy('c.id', 'ASC')
//            ->setMaxResults(10)
//            ->getQuery()
//            ->getResult()
//        ;
//    }

//    public function findOneBySomeField($value): ?Command
//    {
//        return $this->createQueryBuilder('c')
//            ->andWhere('c.exampleField = :val')
//            ->setParameter('val', $value)
//            ->getQuery()
//            ->getOneOrNullResult()
//        ;
//    }
}
