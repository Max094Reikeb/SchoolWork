function ajouterAuPanier(id) {
    var imagesDest = 0;
    var panier = document.getElementById("panier");
    var elementSrc = document.getElementById("source");
    var elementDest = document.getElementById("destination");
    var elementImg = document.getElementById(id);
    if (elementImg.parentNode.id == "source") {
        elementDest.appendChild(elementImg);
        imagesDest++;
        var total = imagesDest * 7.50;
        panier.innerHTML = parseInt(total) + "&#8364;" + (((total - parseInt(total)) * 100));
    } else {
        elementSrc.appendChild(elementImg);
        imagesDest--;
        panier.innerHTML = imagesDest + " &#8364;";
    }
}
