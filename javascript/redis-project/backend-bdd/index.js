const express = require('express');
const cors = require('cors');
const redis = require('redis');

const app = express();

app.use(express.json());
app.use(express.urlencoded({extended: true}));

app.use(cors({
    origin: '*',
    methods: ['GET', 'POST', 'DELETE', 'PUT']
}));

const redisClient = redis.createClient({
    password: 'RtEyLVYd9BAoqzZ0Yt8DodrMXKScclyW',
    socket: {
        host: 'redis-14130.c1.us-central1-2.gce.redns.redis-cloud.com',
        port: 14130
    }
});

redisClient.connect();

redisClient.on('error', (err) => {
    console.log('Redis error:', err);
});

redisClient.on('connect', () => {
    console.log('Connected to Redis');
});

app.post('/set', (req, res) => {
    const {key, value} = req.body;

    if (typeof key !== 'string' || typeof value !== 'string') {
        console.error('Invalid key or value. Both must be strings.');
        return res.status(400).json({error: 'Invalid key or value. Both must be strings.'});
    }

    if (!key || !value) {
        console.error('Key or value is empty.');
        return res.status(400).json({error: 'Key and value cannot be empty.'});
    }

    redisClient.set(key, value)
        .then(reply => {
            console.log(`Data stored successfully. Redis reply: ${reply}`);
            res.json({message: 'Data stored successfully', reply});
        })
        .catch(err => {
            console.error('Error setting data in Redis:', err);
            res.status(500).json({error: 'Failed to set value in Redis'});
        });
});

app.get('/get/:key', (req, res) => {
    const key = req.params.key;

    redisClient.get(key)
        .then(reply => {
            if (reply !== null) {
                return res.json({value: reply});
            } else {
                return res.json({message: 'No value found for this key'});
            }
        })
        .catch(err => {
            console.error('Error getting data from Redis:', err);
            return res.status(500).json({error: 'Failed to retrieve value'});
        });
});

app.get('/getAll', async (req, res) => {
    try {
        const keys = await redisClient.keys('*');

        if (!keys.length) {
            return res.json({message: 'Aucune note trouvée.'});
        }

        const values = await Promise.all(keys.map(async (key) => {
            const value = await redisClient.get(key);
            return {key, value};
        }));

        res.json(values);
    } catch (err) {
        console.error('Error retrieving data from Redis:', err);
        res.status(500).json({error: 'Erreur lors de la récupération des données de Redis.'});
    }
});

app.delete('/delete/:key', async (req, res) => {
    const key = req.params.key;

    try {
        const result = await redisClient.del(key);
        if (result === 1) {
            res.json({message: `Clé ${key} supprimée avec succès.`});
        } else {
            res.status(404).json({message: `Clé ${key} non trouvée.`});
        }
    } catch (err) {
        console.error('Erreur lors de la suppression de la clé:', err);
        res.status(500).json({error: 'Erreur lors de la suppression de la clé.'});
    }
});

app.listen(3000, () => {
    console.log('Server running on port 3000');
});
