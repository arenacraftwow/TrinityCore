import React from 'react';
import './Root.css';
import { AboutPage } from 'pages/AboutPage/AboutPage';
import { HomePage } from 'pages/HomePage/HomePage';

export function Root() {
    return (
        <div className="Root">
            <nav className="Root-navigation">
                <h1>ArenaCraft Project</h1>
                <ul>
                    <li>
                        <a href="#/">Home</a>
                    </li>
                    <li>
                        <span className="seperator">/</span>
                    </li>
                    <li>
                        <a className="selected" href="#/">About*</a>
                    </li>
                    <li>
                        <span className="seperator">/</span>
                    </li>
                    <li>
                        <a href="#/">Create Account</a>
                    </li>
                    <li>
                        <span className="seperator">/</span>
                    </li>
                    <li>
                        <a href="#/">Discord🡕</a>
                    </li>
                    <li>
                        <span className="seperator">/</span>
                    </li>
                    <li>
                        <a href="#/">Source Code🡕</a>
                    </li>
                </ul>
            </nav>
            <main className="Root-children-container">
                <AboutPage />
                <HomePage />
            </main>
        </div>
    )
}