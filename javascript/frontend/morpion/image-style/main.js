function getRawName(path) {
    return path.replace(/^.*[\\\/]/, '');
}

function rechercherVainqueur(pions, joueurs, tour) {
    if (
        getRawName(pions[0].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[1].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[2].src) == (joueurs[tour] + ".png")
    ) return true;

    if (
        getRawName(pions[3].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[4].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[5].src) == (joueurs[tour] + ".png")
    ) return true;

    if (
        getRawName(pions[6].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[7].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[8].src) == (joueurs[tour] + ".png")
    ) return true;

    if (
        getRawName(pions[0].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[3].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[6].src) == (joueurs[tour] + ".png")
    ) return true;

    if (
        getRawName(pions[1].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[4].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[7].src) == (joueurs[tour] + ".png")
    ) return true;

    if (
        getRawName(pions[2].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[5].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[8].src) == (joueurs[tour] + ".png")
    )  return true;

    if (
        getRawName(pions[0].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[4].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[8].src) == (joueurs[tour] + ".png")
    ) return true;

    if (
        getRawName(pions[2].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[4].src) == (joueurs[tour] + ".png") &&
        getRawName(pions[6].src) == (joueurs[tour] + ".png")
    ) return true;
}

function draw(pions) {

    for (var i = 0; i < 9; i++) {
        if (getRawName(pions[i].src) == "blank.png") return false;
    }

    return true;
}

window.onload = function main() {
    var pions = document.querySelectorAll("#Jeu img");
    var joueurs = ["croix", "rond"];
    var tour = 0;
    var gameOver = false;
    var affichage = document.getElementById("StatutJeu");
    affichage.innerHTML = "Le jeu peut commencer ! <br /> Joueur " + joueurs[tour] + " c'est votre tour.";
    pions.forEach(pion => {
        pion.addEventListener("click", (event) => {
            console.log(event.target.id);
            if (gameOver) return;

            if (!(getRawName(event.target.src) == "blank.png")) {
                affichage.innerHTML = "Case occupée ! <br />Joueur " + joueurs[tour] + " c'est toujours à vous !";
            } else {
                event.target.src = "images/" + joueurs[tour] + ".png";
                gameOver = rechercherVainqueur(pions, joueurs, tour);

                if (gameOver) {
                    affichage.innerHTML = "Le joueur " + joueurs[tour] + ' a gagné ! <br /> <a href="morpion.html">Rejouer</a>';
                    return;
                }

                if (draw(pions)) {
                    affichage.innerHTML = 'Match Nul ! <br/> <a href="morpion.html">Rejouer</a>';
                    return;
                }

                tour++;
                tour = tour % 2;
                affichage.innerHTML = "Joueur " + joueurs[tour] + " c'est à vous !";
            }
        });
    });
}
