const play = {};

function shuffle(array) {
    const shuffledArray = [...array];
    for (let i = shuffledArray.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [shuffledArray[i], shuffledArray[j]] = [shuffledArray[j], shuffledArray[i]];
    }
    return shuffledArray;
}

play.register = () => {
    const playerName = document.getElementById('playerNameInput').value;
    players.list.push({name: playerName});
    document.getElementById('main').innerHTML = Mustache.render(game.view.register, players)
}

play.launch = () => {
    if (players.list.length < 2) {
        alert('Vous avez besoin d\'au moins 2 joueurs pour lancer la partie !');
        return;
    }

    // TODO: Start game logic

    const shuffledCards = shuffle(cards.cards);
    const numPlayers = players.list.length;

    for (let i = 0; i < numPlayers; i++) {
        const startIndex = i * 7;
        const endIndex = startIndex + 7;
        players[i].hand = shuffledCards.slice(startIndex, endIndex);
    }

    // TODO: Start game logic with rules and all
}
