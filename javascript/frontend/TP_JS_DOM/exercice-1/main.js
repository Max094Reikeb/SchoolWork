function addElements() {
    var student = prompt("Entrez le nom de l'élève");
    var nav = navigator.appName;
    var system = navigator.platform;

    var nouveau = document.createElement("div");
    nouveau.className = "box";

    var content = document.getElementById("affichage");

    nouveau.innerHTML = "Bonjour " + student + " ! <br /> Vous êtes élève en CPI2 à CY Tech <br /> Votre navigateur est: " +
        nav + "<br /> Votre système d'exploitation est: " + system + "<br />";
    content.appendChild(nouveau);
}

function deleteElement() {
    var content = document.getElementById("affichage");
    content.removeChild(content.lastChild);
}

function deleteAll() {
    window.location.href = "exercice1.html";
}