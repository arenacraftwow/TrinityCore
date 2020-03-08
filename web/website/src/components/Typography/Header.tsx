import React from 'react';
import './Typography.css';

export const Header: React.SFC = (props) => {
    return (
        <>
            <h3 className="Header">
                <span className="Header-content">{props.children}</span>
                <div className="Header-underline"></div>
            </h3>
        </>
    )
}

Header.displayName = 'Header';