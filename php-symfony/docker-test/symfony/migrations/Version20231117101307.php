<?php

declare(strict_types=1);

namespace DoctrineMigrations;

use Doctrine\DBAL\Schema\Schema;
use Doctrine\Migrations\AbstractMigration;

/**
 * Auto-generated Migration: Please modify to your needs!
 */
final class Version20231117101307 extends AbstractMigration
{
    public function getDescription(): string
    {
        return '';
    }

    public function up(Schema $schema): void
    {
        // this up() migration is auto-generated, please modify it to your needs
        $this->addSql('CREATE TABLE address (id INT AUTO_INCREMENT NOT NULL, restaurant_id INT NOT NULL, street VARCHAR(255) NOT NULL, city VARCHAR(255) NOT NULL, state VARCHAR(255) NOT NULL, country VARCHAR(255) NOT NULL, postal_code VARCHAR(255) NOT NULL, UNIQUE INDEX UNIQ_D4E6F81B1E7706E (restaurant_id), PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE command (id INT AUTO_INCREMENT NOT NULL, owner_id INT NOT NULL, total_amount INT NOT NULL, INDEX IDX_8ECAEAD47E3C61F9 (owner_id), PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE command_product (command_id INT NOT NULL, product_id INT NOT NULL, INDEX IDX_3C20574E33E1689A (command_id), INDEX IDX_3C20574E4584665A (product_id), PRIMARY KEY(command_id, product_id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE product (id INT AUTO_INCREMENT NOT NULL, restaurant_id INT NOT NULL, name VARCHAR(255) NOT NULL, price INT NOT NULL, INDEX IDX_D34A04ADB1E7706E (restaurant_id), PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('CREATE TABLE restaurant (id INT AUTO_INCREMENT NOT NULL, name VARCHAR(255) NOT NULL, type VARCHAR(255) NOT NULL, PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB');
        $this->addSql('ALTER TABLE address ADD CONSTRAINT FK_D4E6F81B1E7706E FOREIGN KEY (restaurant_id) REFERENCES restaurant (id)');
        $this->addSql('ALTER TABLE command ADD CONSTRAINT FK_8ECAEAD47E3C61F9 FOREIGN KEY (owner_id) REFERENCES person (id)');
        $this->addSql('ALTER TABLE command_product ADD CONSTRAINT FK_3C20574E33E1689A FOREIGN KEY (command_id) REFERENCES command (id) ON DELETE CASCADE');
        $this->addSql('ALTER TABLE command_product ADD CONSTRAINT FK_3C20574E4584665A FOREIGN KEY (product_id) REFERENCES product (id) ON DELETE CASCADE');
        $this->addSql('ALTER TABLE product ADD CONSTRAINT FK_D34A04ADB1E7706E FOREIGN KEY (restaurant_id) REFERENCES restaurant (id)');
        $this->addSql('ALTER TABLE transaction DROP FOREIGN KEY FK_723705D1204C4EAA');
        $this->addSql('ALTER TABLE transaction DROP FOREIGN KEY FK_723705D16813E404');
        $this->addSql('ALTER TABLE account DROP FOREIGN KEY FK_7D3656A47E3C61F9');
        $this->addSql('DROP TABLE transaction');
        $this->addSql('DROP TABLE account');
    }

    public function down(Schema $schema): void
    {
        // this down() migration is auto-generated, please modify it to your needs
        $this->addSql('CREATE TABLE transaction (id INT AUTO_INCREMENT NOT NULL, debit_account_id INT NOT NULL, credit_account_id INT NOT NULL, amount INT NOT NULL, date DATETIME NOT NULL, label VARCHAR(255) CHARACTER SET utf8mb4 NOT NULL COLLATE `utf8mb4_unicode_ci`, INDEX IDX_723705D1204C4EAA (debit_account_id), INDEX IDX_723705D16813E404 (credit_account_id), PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB COMMENT = \'\' ');
        $this->addSql('CREATE TABLE account (id INT AUTO_INCREMENT NOT NULL, owner_id INT NOT NULL, iban VARCHAR(255) CHARACTER SET utf8mb4 NOT NULL COLLATE `utf8mb4_unicode_ci`, balance INT NOT NULL, min_balance INT NOT NULL, type VARCHAR(255) CHARACTER SET utf8mb4 NOT NULL COLLATE `utf8mb4_unicode_ci`, INDEX IDX_7D3656A47E3C61F9 (owner_id), PRIMARY KEY(id)) DEFAULT CHARACTER SET utf8mb4 COLLATE `utf8mb4_unicode_ci` ENGINE = InnoDB COMMENT = \'\' ');
        $this->addSql('ALTER TABLE transaction ADD CONSTRAINT FK_723705D1204C4EAA FOREIGN KEY (debit_account_id) REFERENCES account (id) ON UPDATE NO ACTION ON DELETE NO ACTION');
        $this->addSql('ALTER TABLE transaction ADD CONSTRAINT FK_723705D16813E404 FOREIGN KEY (credit_account_id) REFERENCES account (id) ON UPDATE NO ACTION ON DELETE NO ACTION');
        $this->addSql('ALTER TABLE account ADD CONSTRAINT FK_7D3656A47E3C61F9 FOREIGN KEY (owner_id) REFERENCES person (id) ON UPDATE NO ACTION ON DELETE NO ACTION');
        $this->addSql('ALTER TABLE address DROP FOREIGN KEY FK_D4E6F81B1E7706E');
        $this->addSql('ALTER TABLE command DROP FOREIGN KEY FK_8ECAEAD47E3C61F9');
        $this->addSql('ALTER TABLE command_product DROP FOREIGN KEY FK_3C20574E33E1689A');
        $this->addSql('ALTER TABLE command_product DROP FOREIGN KEY FK_3C20574E4584665A');
        $this->addSql('ALTER TABLE product DROP FOREIGN KEY FK_D34A04ADB1E7706E');
        $this->addSql('DROP TABLE address');
        $this->addSql('DROP TABLE command');
        $this->addSql('DROP TABLE command_product');
        $this->addSql('DROP TABLE product');
        $this->addSql('DROP TABLE restaurant');
    }
}
