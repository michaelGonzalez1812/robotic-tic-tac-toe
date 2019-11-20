// Game.js

import React, { Component } from 'react';
import { View, Text, Button, TouchableOpacity, Image, Alert } from 'react-native';
import styles from './styles/gameBoard'
import images from './images'
import Header from './Header'
//import SoundPlayer from 'react-native-sound-player'

// clase para manejar la logica y visualizacion del juego
export class Game extends React.Component {
  constructor(props) {
    super(props)
    
    
 
    // try {
    // // play the file tone.mp3
    // SoundPlayer.playSoundFile('../../assets/pokeMusic', 'mp3')
    // // or play from url
    // // SoundPlayer.playUrl('https://drive.google.com/open?id=1jkEWSb3GVfTK8x8Vp6A12KctOXThbwCf')
    // } catch (e) {
    // console.log(`cannot play the sound file`, e)
    // }

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
      player1Logo: props.navigation.state.params.player1Logo,
      player2Logo: props.navigation.state.params.player2Logo,
      player1Name: props.navigation.state.params.player1Name,
      player2Name: props.navigation.state.params.player2Name,
      player1Score: 0,
      player2Score: 0,
      win:0,
      size:props.navigation.state.params.size,
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
    let mtrx = this.state.matrix.slice()
    if (this.state.playerTurn == 1) {
      sym = this.state.player1Logo
      mtrx[index] = 1
      this.setState({
        playerTurn: 2,
        matrix: mtrx,

      })
      this.changeSquare(index, sym)
    } else if (this.state.playerTurn == 2) {
      sym = this.state.player2Logo
      mtrx[index] = 2
      this.setState({
        playerTurn: 1,
        matrix: mtrx,
      })
      this.changeSquare(index, sym)

    }
    switch (sym) {//define la variable que se enviara la servidor para indicar el simbolo a pintar
      case images.symbol1:
        sym2 = 1
        break
      case images.symbol2:
        sym2 = 2
        break
      case images.symbol3:
        sym2 = 3
        break
      default:
        sym2 = 0
    }
    console.log(this.state.matrix)
    this.isWinCondition()
    this.sendState(index, sym2,this.state.size,this.state.win)
    this.isFull()
    
  }

  //funcion para verificar si el trablero esta lleno
  isFull(){
    let mtrx = this.state.matrix
    let full = 1//1 significa que no hay ningun espacio vacio
    mtrx.forEach(elemet=>{
      if (elemet==0){
        full = 0
      }
    })
    if(full){
      this.setState({
        square1: images.symbol0,
        square2: images.symbol0,
        square3: images.symbol0,
        square4: images.symbol0,
        square5: images.symbol0,
        square6: images.symbol0,
        square7: images.symbol0,
        square8: images.symbol0,
        square9: images.symbol0,
        matrix: Array(9).fill(0),
      })
  
    Alert.alert(
      'Draw!',
      'Play again!',
    )
    }
  }

  //funcion para analizar estado de gane
  isWinCondition = () => {
    let mtrx = this.state.matrix
    let a1 = mtrx.slice(0, 3)
    let a2 = mtrx.slice(3, 6)
    let a3 = mtrx.slice(6)
    let a4 = [mtrx[0], mtrx[3], mtrx[6]]
    let a5 = [mtrx[1], mtrx[4], mtrx[7]]
    let a6 = [mtrx[2], mtrx[5], mtrx[8]]
    let a7 = [mtrx[0], mtrx[4], mtrx[8]]
    let a8 = [mtrx[6], mtrx[4], mtrx[2]]
    let check = [a1, a2, a3, a4, a5, a6, a7, a8]
    let win = this.state.win
    check.forEach(elemet => {
      if (elemet[0] == elemet[1] && elemet[1] == elemet[2]) {
        if(elemet[0]!=0){
          console.log('Win State detected')
          this.setState({win:elemet[0]})
          this.handleWin(elemet[0])
        }
        
      }
    })
  }

  handleWin = (winner) => {
    console.log('in hWin player'+String(winner))
    if(winner==1){
      this.setState({
        player1Score : this.state.player1Score+1
      })
    }
    else{
      this.setState({
        player2Score : this.state.player2Score+1
      })
    }
    this.setState({
      square1: images.symbol0,
      square2: images.symbol0,
      square3: images.symbol0,
      square4: images.symbol0,
      square5: images.symbol0,
      square6: images.symbol0,
      square7: images.symbol0,
      square8: images.symbol0,
      square9: images.symbol0,
      matrix: Array(9).fill(0),
  })

  var message ='Player '+ winner.toString(10) + ' wins'
  Alert.alert(
    'Winner!',
    message,
  )


 

  }

  //funcion para comunicar estado del programa a travez de websockets
  sendState = (index, symbol) => {
    console.log('Sending message')
    str = String(index) + String(symbol)
    console.log(str)
    try {
      this.props.screenProps.socketClient.send(JSON.stringify({ 
        pos: index, 
        symbol: symbol,
        size:this.state.size,
        win: this.state.win 
      }))
    } catch (error) {
      console.log(error) // catch error
    }
    this.setState({win:0})
  }

  render() {
    return (
      <View style={styles.container} >

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
          <TouchableOpacity style={styles.pos1} activeOpacity={0.5} onPress={() => { this.handleOnTouch(0) }} >
            <Image
              style={styles.square}
              source={this.state.square1}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos2} activeOpacity={0.5} onPress={() => { this.handleOnTouch(1) }}>
            <Image
              style={styles.square}
              source={this.state.square2}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos3} activeOpacity={0.5} onPress={() => { this.handleOnTouch(2) }}>
            <Image
              style={styles.square}
              source={this.state.square3}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos4} activeOpacity={0.5} onPress={() => { this.handleOnTouch(3) }}>
            <Image
              style={styles.square}
              source={this.state.square4}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos5} activeOpacity={0.5} onPress={() => { this.handleOnTouch(4) }}>
            <Image
              style={styles.square}
              source={this.state.square5}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos6} activeOpacity={0.5} onPress={() => { this.handleOnTouch(5) }}>
            <Image
              style={styles.square}
              source={this.state.square6}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos7} activeOpacity={0.5} onPress={() => { this.handleOnTouch(6) }}>
            <Image
              style={styles.square}
              source={this.state.square7}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos8} activeOpacity={0.5} onPress={() => { this.handleOnTouch(7) }}>
            <Image
              style={styles.square}
              source={this.state.square8}
            />
          </TouchableOpacity>
          <TouchableOpacity style={styles.pos9} activeOpacity={0.5} onPress={() => { this.handleOnTouch(8) }}>
            <Image
              style={styles.square}
              source={this.state.square9}
            />
          </TouchableOpacity>
        </View>

        <View style={styles.info}>
          <Header screenProps={
            {
              player1Logo: this.state.player1Logo,
              player1Name: this.state.player1Name,
              player1Score: this.state.player1Score,
              player2Logo: this.state.player2Logo,
              player2Name: this.state.player2Name,
              player2Score: this.state.player2Score,
            }
          } />
        </View>

      </View>
    )
  }
};






export default Game;