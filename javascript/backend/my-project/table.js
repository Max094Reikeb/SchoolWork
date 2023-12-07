import promptSync from 'prompt-sync';

function randomTable(size) {
    const table = [];
    // On remplit le tableau selon la taille entrée
    for (let i = 0; i < size; i++) {
        table[i] = Math.floor(Math.random() * 101);
    }
    return table;
}

function threeTable(table) {
    // On filtre le tableau pour ne garder que les multiples de 3.
    const multipleTable = table.filter((number) => number % 3 === 0);
    // On retourne notre tableau filtré par ordre croissant
    return multipleTable.sort((a, b) => a - b);
}

// On demande à l'utilisateur la taille de son tableau aléatoire
const prompt = promptSync('');
const size = prompt("Entrez la taille de votre tableau aléatoire: ", "", Intl);
const table = randomTable(size);
console.log("Tableau aléatoire de", size, "cases:", table);
const threeMultipleTable = threeTable(table);
console.log("Le même tableau, mais que avec les multiples de 3:", threeMultipleTable);