import {MongoClient} from "mongodb";
import OAuth2Server from "oauth2-server";

/**
 * We setup the MongoDB client for OAuth database.
 */
const client = new MongoClient("mongodb://localhost:27017");
await client.connect();
const db = client.db("test");
const tokensDb = db.collection("oauthTokens");
const usersDb = db.collection("oauthUsers");
const clientsDb = db.collection("oauthClients");

/**
 * Setup of the OAuth model
 */
const model = {
    getAccessToken: async (bearerToken) => await tokensDb.findOne({accessToken: bearerToken}),
    getClient: async (clientId, clientSecret) => await clientsDb.findOne({
        clientId: clientId,
        clientSecret: clientSecret
    }),
    getRefreshToken: async (refreshToken) => await tokensDb.findOne({refreshToken: refreshToken}),
    getUser: async (username, password) => await usersDb.findOne({username: username, password: password}),
    saveToken: (token, client, user) => {
        const newToken = {
            accessToken: token.accessToken,
            accessTokenExpiresAt: token.accessTokenExpiresAt,
            clientId: client.clientId,
            refreshToken: token.refreshToken,
            refreshTokenExpiresAt: token.refreshTokenExpiresAt,
            userId: user.id,
            client: client,
            user: user
        };
        tokensDb.insertOne(newToken);
        return newToken;
    }
}

/**
 * Setup of the OAuth server
 */
const oauth = new OAuth2Server({
    model,
    accessTokenLifetime: 3600,
    refreshTokenLifetime: 1209600,
    allowBearerTokensInQueryString: true
});

/**
 * Function to check for the user authentication
 */
export function authenticateRequest(req, res, next) {
    const request = new OAuth2Server.Request(req);
    const response = new OAuth2Server.Response(res);
    oauth.authenticate(request, response)
        .then(() => {
            next();
        }).catch((err) => {
        res.status(err.code || 500).json(err);
    });
}

export {oauth};
