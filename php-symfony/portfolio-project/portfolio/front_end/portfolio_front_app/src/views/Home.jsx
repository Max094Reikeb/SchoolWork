import React from "react";
import Header from "../components/layouts/Header";
import {Link} from "react-router-dom";

function Home() {
    return (
        <div style={{ paddingTop: "2rem" }}>
            <Header title="Bienvenue sur mon portfolio" />
            <p>Je suis étudiant à ESIEE-IT, alternant développeur web.</p>
            <p>Vous pouvez me contacter via le formulaire de contact</p>
            <p>
                <Link to="/contact">Me contacter</Link>
            </p>
        </div>
    );
}

export default Home;