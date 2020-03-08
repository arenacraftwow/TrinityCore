import React from 'react';
import './AboutPage.css';
import { Section } from 'components/Typography/Section';
import { Header } from 'components/Typography/Header';
import { Text } from 'components/Typography/Text';

export function AboutPage() {
    return (
        <div className="AboutPage-root">
            <Section>
                <Header>What is ArenaCraft?</Header>
                <Text>
                    <i>ArenaCraft</i> is a arena focused WoW server. The project is based on the 3.3.5a branch of <a href="https://github.com/trinitycore/trinitycore">TrinityCore🡕</a> 
                    &nbsp; with all of our modifications (including this site) being <a href="http://github.com/arenacraftwow/trinitycore">open source</a>. 
                    Our goal is to create a place to skirmish your frirends at and experiment with C++.
                </Text>
            </Section>
            <Section>
                <Header>What is ArenaCraft not?</Header>
                <Text>
                    We are not a <del><code>'serious' big 10k pop pls donate</code></del> traditional server, nor we do not strive to be one. All growth IF ANY will happen organically.
                 </Text>
            </Section>
        </div>
    )
}