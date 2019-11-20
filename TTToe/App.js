import React from 'react';
import { StyleSheet, View, Text } from 'react-native';
import { createAppContainer } from 'react-navigation';
import { createStackNavigator } from 'react-navigation-stack';
import Game from './components/screens/Game';
import Home from './components/screens/Home';


const AppNavigator = createStackNavigator(
  {
    Home:Home,
    Game:Game,
  },
  {
    initialRouteName: 'Home',
  }
);


const AppContainer = createAppContainer(AppNavigator);

export default class App extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      dataFromServer:'',

    }
  }
  // preparacion para envio de mensajes con websockets

  ws = new WebSocket('ws://192.168.43.254:3000')
  componentDidMount() {
    this.ws.onopen = () => {
      // on connecting, do nothing but log it to the console
      this.ws.send('React Connecting');
      console.log('connected')
    }

    this.ws.onmessage = msj => {
      // listen to data sent from the websocket server
      this.setState({ dataFromServer: msj })
      console.log(msj)
    }
    this.ws.onclose = () => {
      console.log('disconnected')
      // automatically try to reconnect on connection loss

    }
  }
  
  render() {
  return <AppContainer screenProps={{socketClient:this.ws}}/>;
  }
}

