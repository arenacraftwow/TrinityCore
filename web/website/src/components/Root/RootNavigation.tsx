import React from 'react';
import './Root.css';
import { Link, useRouteMatch } from 'react-router-dom';
import { classNames } from 'util/classNames';


interface NavLinkProps {
    url: string;
}

const NavLink: React.SFC<NavLinkProps> = ({ url, children }) => {
    const isMatched = Boolean(useRouteMatch(url));
    return (
        <Link to={url} className={classNames(isMatched && 'selected')}>{children}{isMatched && '*'}</Link>
    )
}


export function RootNavigation() {
    return (
        <nav className="Root-navigation">
            <h1>ArenaCraft Project</h1>
            <ul>
                <li>
                    <NavLink url='/home'>Home</NavLink>
                </li>
                <li>
                    <span className="seperator">/</span>
                </li>
                <li>
                    <NavLink url='/about'>About</NavLink>
                </li>
                <li>
                    <span className="seperator">/</span>
                </li>
                <li>
                    <NavLink url='/new-account'>Create Account</NavLink>
                </li>
                <li>
                    <span className="seperator">/</span>
                </li>
                <li>
                    <a rel="noopener noreferrer" href="https://discordapp.com" target="_blank">Discord🡕</a>
                </li>
                <li>
                    <span className="seperator">/</span>
                </li>
                <li>
                    <a rel="noopener noreferrer" href="http://github.com/arenacraftwow/trinitycore" target="_blank">Source Code🡕</a>
                </li>
            </ul>
        </nav>
    )
}