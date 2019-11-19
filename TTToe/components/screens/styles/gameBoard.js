// Hoja de estilos css para el fondo del juego
// Tambien maneja las posiciones de los cuadros

import { StyleSheet } from 'react-native'

export default StyleSheet.create({
  container: {
    alignItems: 'center',
    justifyContent: 'center',
    marginTop: 20,
  },
  board: {
    width: 312,
    height: 312,
    borderWidth: 3,
    borderColor: '#000'
  },
  line: {
    position: 'absolute',
    width: 3,
    height: 306,
    backgroundColor: '#000',
    //con transform se maneja un offset para posicionar los objetos 
    transform: [
      { translateX: 100 }
    ]
  },
  square: {
    padding: 10,
    margin: 5,
    height: 85,
    width: 85,
    resizeMode: 'stretch',
    zIndex: 999,
    position:'relative',
    
  },

  pos1:{
    flexDirection: 'row',
    alignItems: 'center',
    backgroundColor: 'transparent',
    borderWidth: 0.5,
    borderColor: 'transparent',
    zIndex: 1,
    height: 85,
    width: 85,
    margin: 5,
    transform: [
      { translateX: 0 },
      { translateY: 5 },
    ]
  },
  pos2: {
    flexDirection: 'row',
    alignItems: 'center',
    backgroundColor: 'transparent',
    borderWidth: 0.5,
    borderColor: 'transparent',
    zIndex: 1,
    height: 85,
    width: 85,
    margin: 5,
    transform: [
      { translateX: 100 },
      { translateY: -90 },
    ]
  },
  pos3: {
    flexDirection: 'row',
    alignItems: 'center',
    backgroundColor: 'transparent',
    borderWidth: 0.5,
    borderColor: 'transparent',
    zIndex: 1,
    height: 85,
    width: 85,
    margin: 5,
    transform: [
      { translateX: 200 },
      { translateY: -185 },
    ]
  },
  pos4: {
    flexDirection: 'row',
    alignItems: 'center',
    backgroundColor: 'transparent',
    borderWidth: 0.5,
    borderColor: 'transparent',
    zIndex: 1,
    height: 85,
    width: 85,
    margin: 5,
    transform: [
      { translateX: 0 },
      { translateY: -180 },
    ]
  },
  pos5: {
    flexDirection: 'row',
    alignItems: 'center',
    backgroundColor: 'transparent',
    borderWidth: 0.5,
    borderColor: 'transparent',
    zIndex: 1,
    height: 85,
    width: 85,
    margin: 5,
    transform: [
      { translateX: 105 },
      { translateY: -275 },
    ]
  },
  pos6: {
    flexDirection: 'row',
    alignItems: 'center',
    backgroundColor: 'transparent',
    borderWidth: 0.5,
    borderColor: 'transparent',
    zIndex: 1,
    height: 85,
    width: 85,
    margin: 5,
    transform: [
      { translateX: 210 },
      { translateY: -370 },
    ]
  },
  pos7: {
    flexDirection: 'row',
    alignItems: 'center',
    backgroundColor: 'transparent',
    borderWidth: 0.5,
    borderColor: 'transparent',
    zIndex: 1,
    height: 85,
    width: 85,
    margin: 5,
    transform: [
      { translateX: 0 },
      { translateY: -360 },
    ]
  },
  pos8: {
    flexDirection: 'row',
    alignItems: 'center',
    backgroundColor: 'transparent',
    borderWidth: 0.5,
    borderColor: 'transparent',
    zIndex: 1,
    height: 85,
    width: 85,
    margin: 5,
    transform: [
      { translateX: 100 },
      { translateY: -455},
    ]
  },
  pos9: {
    flexDirection: 'row',
    alignItems: 'center',
    backgroundColor: 'transparent',
    borderWidth: 0.5,
    borderColor: 'transparent',
    zIndex: 1,
    height: 85,
    width: 85,
    margin: 5,
    transform: [
      { translateX: 200 },
      { translateY: -555},
    ]
  },

  logos:{
    margin: 5,
    height: 20,
    width: 20,
    borderWidth: 0.5,
    borderColor: '#000',
    resizeMode: 'stretch',
    alignSelf: 'center',
  },
  info:{
    margin: 5,
    flexDirection: 'column',
    alignSelf: 'center',
  },
  infoContainer: {
    flexDirection: 'row',
    alignSelf:'stretch',
    alignSelf: 'center',
  },

})
