// Game.js

import React, { Component } from 'react';
import { View, Text, Button, TouchableOpacity, Image } from 'react-native';
import styles from './styles/gameBoard'
import images from './images'

// clase para manejar la logica y visualizacion del juego
export class Game extends  React.Component {
  constructor(props) {
    super(props)
    this.state = {
      //variables para guardar el dibujo que se debe pintar en cada cuadro
      square1: images.symbol0,
      square2: images.symbol0,
      square3: images.symbol0,
      square4: images.symbol0,
      square5: images.symbol0,
      square6: images.symbol0,
      square7: images.symbol0,
      square8: images.symbol0,
      square9: images.symbol0,
      playerTurn: 1,
      player1Logo: images.symbol1,
      player2Logo: images.symbol2,
      //variable para la logica de gane del juego
      matrix: Array(9).fill(0),

    }
  }







  // funcion para cambiar lo que se pinta en un cuadro especifico
  // index indica cual cuadtro
  // sym indica que simbolo pintar
  changeSquare = (index, sym) => {
    switch (index) {
      case 0:
        this.setState({
          square1: sym
        })
        break;
      case 1:
        this.setState({
          square2: sym
        })
        break;
      case 2:
        this.setState({
          square3: sym
        })
        break;
      case 3:
        this.setState({
          square4: sym
        })
        break;
      case 4:
        this.setState({
          square5: sym
        })
        break;
      case 5:
        this.setState({
          square6: sym
        })
        break;
      case 6:
        this.setState({
          square7: sym
        })
        break;
      case 7:
        this.setState({
          square8: sym
        })
        break;
      case 8:
        this.setState({
          square9: sym
        })
        break;

      default:
        console.log('Error')
    }

  }

  //funcion de respuesta al tocar un cuadro, maneja las llamadas al resto de logica del juego
  handleOnTouch = (index) => {
    let sym
    let sym2
    let mtrx= this.state.matrix.slice()
    if (this.state.playerTurn == 1) {
      sym = this.state.player1Logo
      mtrx[index]=1
      this.setState({
        playerTurn: 2,
        matrix:mtrx,

      })
      this.changeSquare(index,sym)
    } else if(this.state.playerTurn == 2){
      sym = this.state.player2Logo
      mtrx[index]=2
      this.setState({
        playerTurn: 1,
        matrix:mtrx,
      })
      
      this.changeSquare(index,sym)
      
    }
    switch (sym){
      case images.symbol1:
        sym2=1
        break
      case images.symbol2:
        sym2=2
      case images.symbol3:
        sym2=3
      default:
        sym2=0    
    }
    console.log(this.state.matrix)
    this.sendState(index,sym2)
  }

  //funcion para analizar estado de gane
  isWinCondition = () => {
    
  }

  

  //funcion para comunicar estado del programa a travez de websockets
  sendState = (index,symbol) => {
    console.log('Sending message')
    str = String(index)+String(symbol)
    console.log(str)
    try {
      this.props.screenProps.socketClient.send(JSON.stringify({pos:index,symbol:symbol}))
    } catch (error) {
      console.log(error) // catch error
  }

  }

  render() {
    return (
      <View style={styles.container}>

        <View style={styles.board}>
          <View
            style={styles.line}
          />
          <View
            style={[styles.line, {
              width: 3,
              height: 306,
              transform: [
                { translateX: 200 }
              ]
            }]}
          />
          <View
            style={[styles.line, {
              width: 306,
              height: 3,
              transform: [
                { translateY: 100 }
              ]
            }]}
          />
          <View
            style={[styles.line, {
              width: 306,
              height: 3,
              transform: [
                { translateY: 200 }
              ]
            }]}
          />
          <TouchableOpacity style={styles.pos1} activeOpacity={0.5} onPress={()=>{this.handleOnTouch(0)}} >
            <Image
              style={styles.square}
              source={this.state.square1}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos2} activeOpacity={0.5} onPress={()=>{this.handleOnTouch(1)}}>
            <Image
              style={styles.square}
              source={this.state.square2}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos3} activeOpacity={0.5} onPress={()=>{this.handleOnTouch(2)}}>
            <Image
              style={styles.square}
              source={this.state.square3}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos4} activeOpacity={0.5} onPress={()=>{this.handleOnTouch(3)}}>
            <Image
              style={styles.square}
              source={this.state.square4}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos5} activeOpacity={0.5} onPress={()=>{this.handleOnTouch(4)}}>
            <Image
              style={styles.square}
              source={this.state.square5}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos6} activeOpacity={0.5} onPress={()=>{this.handleOnTouch(5)}}>
            <Image
              style={styles.square}
              source={this.state.square6}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos7} activeOpacity={0.5} onPress={()=>{this.handleOnTouch(6)}}>
            <Image
              style={styles.square}
              source={this.state.square7}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos8} activeOpacity={0.5} onPress={()=>{this.handleOnTouch(7)}}>
            <Image
              style={styles.square}
              source={this.state.square8}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos9} activeOpacity={0.5} onPress={()=>{this.handleOnTouch(8)}}>
            <Image
              style={styles.square}
              source={this.state.square9}
            />
          </TouchableOpacity>
        </View>
      </View>
    )
  }
};






export default Game;