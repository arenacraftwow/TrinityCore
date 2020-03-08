import React, { useState, useEffect } from 'react';
import './Root.css';
import { AboutPage } from 'pages/AboutPage/AboutPage';
import { HomePage } from 'pages/HomePage/HomePage';
import { RootNavigation } from './RootNavigation';
import { Route, Switch, Redirect, useLocation } from 'react-router-dom';
import { Alert } from 'components/Alert/Alert';

interface _NavigationState {
    fromNotFoundPage: boolean;
}

export type NavigationState = Partial<_NavigationState>


export function Root() {
    const location = useLocation<NavigationState>();
    const fromNotFoundPage = Boolean((location.state || {}).fromNotFoundPage);
    const [showPageNotFoundAlert, setShowPageNotFoundAlert] = useState(false);

    useEffect(() => {
        setShowPageNotFoundAlert(fromNotFoundPage);
    }, [fromNotFoundPage])

    return (
        <div className="Root">
            <RootNavigation />
            <main className="Root-children-container">
                {showPageNotFoundAlert &&
                    <Alert 
                    type='warning'
                    onCloseRequest={() => setShowPageNotFoundAlert(false)}
                    >
                        The page you were trying to visit does not exist
                    </Alert>}
                <Switch>
                    <Route path='/home'>
                        <HomePage />
                    </Route>
                    <Route path='/about'>
                        <AboutPage />
                    </Route>
                    <Route>
                        <Redirect to={{ pathname: '/home', state: { fromNotFoundPage: true } }} />
                    </Route>
                </Switch>
            </main>
        </div>
    )
}