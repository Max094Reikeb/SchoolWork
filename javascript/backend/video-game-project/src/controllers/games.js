import {MongoClient} from "mongodb";

// We setup the MongoDB client for game database.
const client = new MongoClient("mongodb://localhost:27017");
await client.connect();
const db = client.db("test");
const gamesDb = db.collection("games");

/**
 * @api {get} /games Get all games
 * @apiName GetGames
 * @apiGroup Games
 *
 * @apiSuccess {Object[]} games List of all games.
 *
 * @apiSuccessExample Success-Response:
 *      HTTP/1.1 200 OK
 *      [
 *          {
 *              "id": 0,
 *              "title": "Pokemon Écarlate",
 *              "editor": "The Pokemon Company",
 *              "platforms":
 *                  [
 *                      "Nintendo Switch"
 *                  ],
 *              "quantity": 40
 *          },
 *          {
 *              "id": 1,
 *              "title": "Zelda Breath of the Wild",
 *              "editor": "Nintendo",
 *              "platforms":
 *                  [
 *                      "Nintendo Switch"
 *                  ],
 *              "quantity": 20
 *          }
 *      ]
 */
export const getGames = async (req, res) => {
    const games = await gamesDb.find().toArray();
    res.json(games);
};

/**
 * @api {get} /games/:id Get game by ID
 * @apiName GetGame
 * @apiGroup Games
 *
 * @apiParam {Number} id Game's unique ID.
 *
 * @apiSuccess {Object} game Details of a game with given ID.
 *
 * @apiSuccessExample Success-Response:
 *      HTTP/1.1 200 OK
 *      {
 *          "id": 0,
 *          "title": "Pokemon Écarlate",
 *          "editor": "The Pokemon Company",
 *          "platforms":
 *              [
 *                  "Nintendo Switch"
 *              ],
 *          "quantity": 40
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
export const getGame = async (req, res) => {
    const game = await gamesDb.find({id: parseInt(req.params.id)}).toArray();
    if (game.length === 0) {
        // In case there is no game found with required ID, we send 404 not found status.
        res.sendStatus(404);
    }
    res.json(game);
}

/**
 * @api {post} /games Create a new game
 * @apiName CreateGame
 * @apiGroup Games
 *
 * @apiParam {Number} id Game's unique ID.
 * @apiParam {String} title Title of the game.
 * @apiParam {String} editor Editor of the game.
 * @apiParam {String[]} platforms Game consoles where tha game can be played.
 * @apiParam {Number} quantity In-stored copies of the game.
 *
 * @apiSuccess {Object} 200 Successful creation of game.
 *
 * @apiSuccessExample Success-Response:
 *      HTTP/1.1 200 OK
 *
 * @apiError {Object} 404 Error inserting game to the database.
 *
 * @apiErrorExample Error-Response:
 *      HTTP/1.1 404 Error inserting game to the database
 *      {
 *          "error": "Error inserting game to the database"
 *      }
 */
export const createGame = (req, res) => {
    const newGame = req.body;
    gamesDb.insertOne(newGame)
        .then(result => {
            if (result.insertedCount === 0) {
                return res.sendStatus(404);
            }
            res.sendStatus(200)
        })
        .catch(() => {
            res.sendStatus(404).send('Error inserting game to the database');
        });
}

/**
 * @api {put} /games/:id Update game by ID
 * @apiName UpdateGame
 * @apiGroup Games
 *
 * @apiParam {Number} id Game's unique ID.
 * @apiParam {String} title Title of the game.
 * @apiParam {String} editor Editor of the game.
 * @apiParam {String[]} platforms Game consoles where tha game can be played.
 * @apiParam {Number} quantity In-stored copies of the game.
 *
 * @apiSuccess {Object} 200 Successful update of game.
 *
 * @apiSuccessExample Success-Response:
 *      HTTP/1.1 200 OK
 *
 * @apiError {Object} 404 Error updating game or game not found.
 *
 * @apiErrorExample Error-Response:
 *      HTTP/1.1 404 Error updating game or game not found
 *      {
 *          "error": "Error updating game or game not found"
 *      }
 */
export const updateGame = (req, res) => {
    gamesDb.updateOne({id: parseInt(req.params.id)},
        {
            $set: {
                title: req.body.title,
                editor: req.body.editor,
                platforms: req.body.platforms,
                quantity: parseInt(req.body.quantity)
            }
        })
        .then(result => {
            if (result.matchedCount === 0) {
                return res.sendStatus(404);
            }
            res.sendStatus(200);
        })
        .catch(() => {
            res.status(404).send('Error updating game or game not found.');
        });
}

/**
 * @api {delete} /games/:id Delete game by ID
 * @apiName DeleteGame
 * @apiGroup Games
 *
 * @apiParam {Number} id Game's unique ID.
 *
 * @apiSuccess {Object} 200 Successful deletion of game.
 *
 * @apiSuccessExample Success-Response:
 *      HTTP/1.1 200 OK
 */
export const deleteGame = async (req, res) => {
    await gamesDb.deleteOne({"id": parseInt(req.params.id)});
    res.sendStatus(200);
}
