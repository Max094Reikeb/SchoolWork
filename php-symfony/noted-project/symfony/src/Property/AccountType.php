<?php

namespace App\Property;

enum AccountType: string
{
    case CompteCourant = 'Compte courant';
    case LivretA = 'Livret A';
    case PEL = 'PEL';
    case LivretJeune = 'Livret Jeune';
    case AssuranceVie = 'Assurance Vie';
}
