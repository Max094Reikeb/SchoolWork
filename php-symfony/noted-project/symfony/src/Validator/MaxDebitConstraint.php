<?php

namespace App\Validator;

use Symfony\Component\Validator\Constraint;

#[\Attribute]
class MaxDebitConstraint extends Constraint
{
    public string $message = "The debit account doesn't have enough money!";

    public function __construct(string $message = null, array $groups = null, $payload = null)
    {
        parent::__construct([], $groups, $payload);
        $this->message = $message ?? $this->message;
    }

    public function validatedBy(): string
    {
        return static::class . 'Validator';
    }

    public function getTargets(): string
    {
        return self::CLASS_CONSTRAINT;
    }
}
