import fs from "fs";

const cachePersons = JSON.parse(fs.readFileSync('persons.json', 'utf8'));

export const getPersons = (req, res) => {
    res.json(cachePersons);
};

export const getPerson = (req, res) => {
    res.json(cachePersons[req.params.id]);
}

export const createPerson = (req, res) => {
    const newPerson = req.body;
    cachePersons.push(newPerson);
    fs.writeFileSync('persons.json', JSON.stringify(cachePersons, null, 2));
    res.sendStatus(200);
}

export const updatePerson = (req, res) => {
    cachePersons[parseInt(req.params.id)] = {
        name: req.body.name,
        age: parseInt(req.body.age)
    };
    fs.writeFileSync('persons.json', JSON.stringify(cachePersons, null, 2));
    res.sendStatus(200);
}

export const deletePerson = (req, res) => {
    cachePersons.splice(parseInt(req.params.id), 1);
    fs.writeFileSync('persons.json', JSON.stringify(cachePersons, null, 2));
    res.sendStatus(200);
}
