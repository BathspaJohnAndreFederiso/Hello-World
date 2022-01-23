import React, {Component} from 'react';
import { View, Text, TextInput, StyleSheet,Button, 
  Alert,TouchableOpacity, PaperProvider } from 'react-native'


class App extends Component{
  render(){
    return(
      <PaperProvider>
         <Text>Hello</Text>
      </PaperProvider>
    );
  }
}
  