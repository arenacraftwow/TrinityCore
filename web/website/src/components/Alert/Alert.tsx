import React from 'react';
import './Alert.css';

interface AlertProps {
    type?: 'info' | 'warning';
    onCloseRequest?(): void;
}

export const Alert: React.SFC<AlertProps> = (props) => {
    const type = props.type || 'info';

    return (
        <div className="Alert">
            <div className="Alert-content-type">
                <span>{type}</span>
                {props.onCloseRequest && <span className="Alert-closer" onClick={props.onCloseRequest}>×</span>}
            </div>
            <div className="Alert-content">{props.children}</div>
        </div>
    )
}


Alert.displayName = 'Alert';