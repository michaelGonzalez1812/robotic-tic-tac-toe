// Home.js

import React, { Component } from 'react';
import { View, Text, Button, TextInput, Image, TouchableOpacity, Alert, Picker } from 'react-native';
import styles from './styles/gameBoard'
import images from './images'

export class Home extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      player1Name:'',
      player2Name:'',
      player1Logo:images.symbol1,
      player2Logo:images.symbol2,
      size:0,

    }
  }
  
  
  //control del boton de seleccion de logo
  handleOnTouch = (player) => {
    if (player==1){
      switch (this.state.player1Logo){
        case images.symbol1:
          this.setState({player1Logo:images.symbol2})
          break
        case images.symbol3:
          this.setState({player1Logo:images.symbol1})
          break
        case images.symbol2:
              this.setState({player1Logo:images.symbol3})
              break
      }
    }
    else{
      switch (this.state.player2Logo){
        case images.symbol1:
          this.setState({player2Logo:images.symbol2})
          break
        case images.symbol3:
          this.setState({player2Logo:images.symbol1})
          break
        case images.symbol2:
          this.setState({player2Logo:images.symbol3})
          break
        
      }
    }
  }
  //control del bboton de inicio de juego
  startGame = () => {
    if(this.state.player1Logo==this.state.player2Logo){
      Alert.alert(
        'Invalid logo',
        'Player logos should be different',
      )
      
    }
    else{
      //transferencia de variables a la vista del juego
      this.props.navigation.navigate("Game",{
        player1Name:this.state.player1Name,
        player2Name:this.state.player2Name,
        player1Logo:this.state.player1Logo,
        player2Logo:this.state.player2Logo,
        size:this.state.size,
      })
    }
    
    
    
  }

  render() {
    return (
      <View>
        <Text>Welcome to Tic Tac Toe Game</Text>

        <View style={styles.infoContainer}>
          <View >
            <Text style={styles.info}>Insert Player 1 Name:</Text>
            <TextInput
              style={{ height: 40, borderColor: 'gray', borderWidth: 1 }}
              onChangeText={player1Name => {
                this.setState({ player1Name });
              }}
              value={this.state.player1Name}
             />
            <Text style={styles.info}>
              Logo:
                    </Text>
            <TouchableOpacity style={styles.logos} activeOpacity={0.5} onPress={()=>{this.handleOnTouch(1)}} >
              <Image
                style={styles.logoSquare}
                source={this.state.player1Logo}
              />
            </TouchableOpacity>

            <Text style={styles.info}>
              Score: {this.props.screenProps.player2Score}
            </Text>
          </View>


          <View >
            <Text style={styles.info}>Insert Player 2 Name:</Text>
            <TextInput
              style={{ height: 40, borderColor: 'gray', borderWidth: 1 }}
              onChangeText={player2Name => {
                this.setState({ player2Name });
              }}
              value={this.state.player2Name}
             />
            <Text style={styles.info}>
              Logo:
            </Text>
            <TouchableOpacity style={styles.logos} activeOpacity={0.5} onPress={()=>{this.handleOnTouch(2)}} >
              <Image
                style={styles.logoSquare}
                source={this.state.player2Logo}
              />
            </TouchableOpacity>

            <Text style={styles.info}>
              Score: {this.props.screenProps.player2Score}
            </Text>
          </View>
        </View>
        
        <Text style={styles.info}>
          Size:      
        </Text>
        <Picker
          selectedValue={this.state.size}
          // style={{height: 50, width: 100}}
          onValueChange={(itemValue, itemIndex) =>
          this.setState({size: itemValue})
        }>
          <Picker.Item label="0" value={0} />
          <Picker.Item label="1" value={1} />
          <Picker.Item label="2" value={2} />
        </Picker>


        <Button
          title="Start Game"
          onPress={this.startGame}
        />
      </View>
    )
  }
}

export default Home