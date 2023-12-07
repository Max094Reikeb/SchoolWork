import promptSync from 'prompt-sync';

function convertOctet(simplified) {
    // On prend le dernier caractère de l'entrée utilisateur (donc K, M, G ou T)
    const indice = simplified.at(-1);
    // On prend l'entrée utilisateur seule sans l'indice
    let converted = simplified.slice(0, -1);
    // On regarde l'indice et on change la valeur de l'octet selon la valeur de l'indice
    switch (indice) {
        case 'K':
            return converted * 1024;
        case 'M':
            return converted * Math.pow(1024, 2);
        case 'G':
            return converted * Math.pow(1024, 3);
        case 'T':
            return converted * Math.pow(1024, 4);
        default:
            console.error("Il semble avoir un problème avec le résultat, votre entrée ne comprenant pas d'indice voulue. Veuillez recommencer avec K, M, G ou T à la fin.")
            return 0;
    }
}

// On demande la forme simplifiée à l'utilisateur
const prompt = promptSync('');
const simplified = prompt("Entrez la forme simplifiée: ", "", String);
const converted = convertOctet(simplified);
console.log("La forme complète est donc:", converted);
