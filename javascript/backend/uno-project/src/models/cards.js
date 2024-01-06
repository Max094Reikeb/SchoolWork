const cards = {};
cards.colors = ['R', 'B', 'V', 'J'];
cards.types = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'F', 'R', 'D', 'C', 'Q'];
cards.cards = [];

cards.generecards = () => {
    cards.colors.forEach(color => {
        cards.types.forEach(type => {
            if (type !== "Q") cards.cards.push({ type, color })
            if (!['0', 'C'].includes(type)) cards.cards.push({ type, color })
        });
    });
    console.log(cards.cards);
    return cards;
}
