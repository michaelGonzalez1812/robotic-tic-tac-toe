// Home.js

import React, { Component } from 'react';
import { View, Text, Button } from 'react-native';

export class Home extends  React.Component {
  render() {
    return (
      <View>
        <Text>Welcome to Tic Tac Toe Game</Text>
        <Button 
            title="Click Me"
            onPress={()=>this.props.navigation.navigate("Game")}
        />
      </View>
    )
  }
}

export default Home