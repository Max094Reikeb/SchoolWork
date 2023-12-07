import {MongoClient} from "mongodb";

// We setup the MongoDB client for customer database.
const client = new MongoClient("mongodb://localhost:27017");
await client.connect();
const db = client.db("test");
const customersDb = db.collection("customers");

/**
 * @api {get} /customers Get all customers
 * @apiName GetCustomers
 * @apiGroup Customers
 *
 * @apiSuccess {Object[]} customers List of all customers.
 *
 * @apiSuccessExample Success-Response:
 *      HTTP/1.1 200 OK
 *      [
 *          {
 *              "id": 0,
 *              "name": "BEKIER",
 *              "firstName": "Maxence",
 *              "dateOfBirth": "2001-02-21T00:00:00.000Z",
 *              "address": "Rue du poirier lointain",
 *              "phoneNumber": "0612345678",
 *              "points": 3
 *          },
 *          {
 *              "id": 1,
 *              "name": "LACAILLE",
 *              "firstName": "Gustave",
 *              "dateOfBirth": "2001-03-24T00:00:00.000Z",
 *              "address": "Boulevard d'Antoine",
 *              "phoneNumber": "0756341298",
 *              "points": 2
 *          }
 *      ]
 */
export const getCustomers = async (req, res) => {
    const customers = await customersDb.find().toArray();
    res.json(customers);
};

/**
 * @api {get} /customers/:id Get customer by ID
 * @apiName GetCustomer
 * @apiGroup Customers
 *
 * @apiParam {Number} id Customer's unique ID.
 *
 * @apiSuccess {Object} customer Details of a customer with given ID.
 *
 * @apiSuccessExample Success-Response:
 *      HTTP/1.1 200 OK
 *      {
 *          "id": 0,
 *          "name": "BEKIER",
 *          "firstName": "Maxence",
 *          "dateOfBirth": "2001-02-21T00:00:00.000Z",
 *          "address": "Rue du poirier lointain",
 *          "phoneNumber": "0612345678",
 *          "points": 3
 *      }
 *
 * @apiError {Object} 404 Not found.
 *
 * @apiErrorExample Error-Response:
 *      HTTP/1.1 404 Not Found
 *      {
 *          "error": "Not Found"
 *      }
 */
export const getCustomer = async (req, res) => {
    const customer = await customersDb.find({id: parseInt(req.params.id)}).toArray();
    if (customer.length === 0) {
        // In case there is no customer found with required ID, we send 404 not found status.
        res.sendStatus(404);
    }
    res.json(customer);
}

/**
 * @api {post} /customers Create a new customer
 * @apiName CreateCustomer
 * @apiGroup Customers
 *
 * @apiParam {Number} id Customer's unique ID.
 * @apiParam {String} name Name of the customer.
 * @apiParam {String} firstName First name of the customer.
 * @apiParam {Date} dateOfBirth Date of birth of the customer.
 * @apiParam {String} address Address of the customer.
 * @apiParam {String} phoneNumber Phone number of the customer.
 * @apiParam {Number} points Loyalty points of the customer.
 *
 * @apiSuccess {Object} 200 Successful creation of customer.
 *
 * @apiSuccessExample Success-Response:
 *      HTTP/1.1 200 OK
 *
 * @apiError {Object} 404 Error inserting customer to the database.
 *
 * @apiErrorExample Error-Response:
 *      HTTP/1.1 404 Error inserting customer to the database
 *      {
 *          "error": "Error inserting customer to the database"
 *      }
 */
export const createCustomer = (req, res) => {
    const newCustomer = req.body;
    customersDb.insertOne(newCustomer)
        .then(result => {
            if (result.insertedCount === 0) {
                return res.sendStatus(404);
            }
            res.sendStatus(200)
        })
        .catch(() => {
            res.sendStatus(404).send('Error inserting customer to the database.');
        });
}

/**
 * @api {put} /customers/:id Update customer by ID
 * @apiName UpdateCustomer
 * @apiGroup Customers
 *
 * @apiParam {Number} id Customer's unique ID.
 * @apiParam {String} name Name of the customer.
 * @apiParam {String} firstName First name of the customer.
 * @apiParam {Date} dateOfBirth Date of birth of the customer.
 * @apiParam {String} address Address of the customer.
 * @apiParam {String} phoneNumber Phone number of the customer.
 * @apiParam {Number} points Loyalty points of the customer.
 *
 * @apiSuccess {Object} 200 Successful update of customer.
 *
 * @apiSuccessExample Success-Response:
 *      HTTP/1.1 200 OK
 *
 * @apiError {Object} 404 Error updating customer or customer not found.
 *
 * @apiErrorExample Error-Response:
 *      HTTP/1.1 404 Error updating customer or customer not found
 *      {
 *          "error": "Error updating customer or customer not found"
 *      }
 */
export const updateCustomer = (req, res) => {
    customersDb.updateOne({id: parseInt(req.params.id)},
        {
            $set: {
                name: req.body.name,
                firstName: req.body.firstName,
                dateOfBirth: req.body.dateOfBirth,
                address: req.body.address,
                phoneNumber: req.body.phoneNumber,
                points: parseInt(req.body.points)
            }
        })
        .then(result => {
            if (result.matchedCount === 0) {
                return res.sendStatus(404);
            }
            res.sendStatus(200);
        })
        .catch(() => {
            res.status(404).send('Error updating customer or customer not found.');
        });
}

/**
 * @api {delete} /customers/:id Delete customer by ID
 * @apiName DeleteCustomer
 * @apiGroup Customers
 *
 * @apiParam {Number} id Customer's unique ID.
 *
 * @apiSuccess {Object} 200 Successful deletion of customer.
 *
 * @apiSuccessExample Success-Response:
 *      HTTP/1.1 200 OK
 */
export const deleteCustomer = async (req, res) => {
    await customersDb.deleteOne({"id": parseInt(req.params.id)});
    res.sendStatus(200);
}
