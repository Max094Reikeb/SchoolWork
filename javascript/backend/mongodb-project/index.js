import { MongoClient } from "mongodb";

const client = new MongoClient("mongodb://localhost:27017");

await client.connect();

const db = client.db("test");
const persons = db.collection("persons");
const newPerson = {
    name: "Edgar ATOA",
    age: 30
};

async function test() {
    await persons.insertOne({name: "Edgar ATOA", age: 30});
    const myPerson = await persons.findOne({name: "Edgar ATOA"});
    console.log(myPerson);
}

test();
