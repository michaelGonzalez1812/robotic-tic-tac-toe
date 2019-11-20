// Header.js
// esta clase controla la informacion que se muestra durante el juego
import React, { Component } from 'react';
import { View, Text, Image } from 'react-native';
import styles from './styles/gameBoard'

export class Header extends React.Component {
    render() {
        return (
            <View style={styles.infoContainer}>
                <View >
                    <Text style={styles.info}>
                        Player 1 {this.props.screenProps.player1Name}:
                    </Text>
                    <Text style={styles.info}>
                        Logo:
                    </Text>
                    <Image
                        style={styles.logos}
                        source={this.props.screenProps.player1Logo}
                    />
                    
                    <Text style={styles.info}>
                        Score: {this.props.screenProps.player1Score}
                    </Text>
                </View>
                <Text>                      </Text>
                <View >
                    <Text style={styles.info}>
                        Player 2 {this.props.screenProps.player2Name}:
                    </Text>
                    <Text style={styles.info}>
                        Logo:
                    </Text>
                    <Image
                        style={styles.logos}
                        source={this.props.screenProps.player2Logo}
                    />
                    
                    <Text style={styles.info}>
                        Score: {this.props.screenProps.player2Score}
                    </Text>
                </View>
            </View>
        )
    }
}

export default Header