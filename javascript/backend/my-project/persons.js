import fs from "fs/promises";

async function asyncReadPersons() {
    await fs.readFile('persons.json', (err, data) => {
        if (err) throw err;
        console.log(JSON.parse(data).sort((a, b) => b.age - a.age));
    });
}

function readPersons() {
    fs.readFile('persons.json', 'utf8')
        .then(data => {
            const persons = JSON.parse(data);
            console.log(persons.sort((a, b) => b.age - a.age));
        })
        .catch(err => {
            console.log("Error reading the file:", err);
        });
}

function averageAge() {
    fs.readFile('persons.json', 'utf8')
        .then(data => {
            const persons = JSON.parse(data);
            // We get the sum of the ages
            const totalAge = persons.reduce((acc, person) => acc + person.age, 0);
            // We compute the average
            const averageAge = totalAge / persons.length;
            console.log("Moyenne d'age:", averageAge);
        })
        .catch(err => {
            console.error("Error reading the file:", err);
        });
}

function copyChildren() {
    fs.readFile('persons.json', 'utf8')
        .then(data => {
            const persons = JSON.parse(data);
            // We filter people younger than 18
            const children = persons.filter(person => person.age < 18);
            return fs.writeFile('children.json', JSON.stringify(children, null, 2));
        })
        .then(() => {
            console.log("Children written!");
        })
        .catch(err => {
            console.error("Error:", err);
        });
}

asyncReadPersons().then(r => console.log("File accessed!"));
readPersons();
averageAge();
copyChildren();
