import express from "express";
import multer from "multer";
import * as gamesController from "../controllers/games.js";

// We start the router and the multer
const router = express.Router();
const upload = multer();

/**
 * First GET router to get all games.
 */
router.get("/", gamesController.getGames);

/**
 * Second GET router to get a game based on its ID.
 */
router.get("/:id", gamesController.getGame);

/**
 * POST router to create a new game.
 */
router.post("/", upload.array(), gamesController.createGame);

/**
 * UPDATE router to update a game's information based on its ID.
 */
router.put("/:id", gamesController.updateGame);

/**
 * DELETE router to delete a game based on its ID.
 */
router.delete("/:id", gamesController.deleteGame);

export default router;
