import * as React from 'react';
import {Component} from 'react';
import { Button, View, Text, Image, TextInput, TouchableOpacity, StyleSheet } from 'react-native';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack'; // imports some navigation features from downloaded react-navigation




function Home({ navigation }) {
 return (
 <View  style={{flex: 1, alignItems: 'center', justifyContent: 'space-around', backgroundColor: 'gray'}}>
 <Text style={styles.titleTxt}>Business Calculator</Text>
 <Image source = {require("./assets/logo.png")} style ={{width: "20%", height: "20%"}}/>
  
  <Button
   title="Calculate for Tip"
   onPress={() => navigation.navigate('Tip Calculator')}
  />
   
  <Button 
   title="Calculate for Simple Interest"
   onPress={() => navigation.navigate('Simple Interest Calculator')}
  />
  

 </View>

 );
}

  class TipCalc extends Component {
  constructor(props){
   super(props);
   this.state ={ n1:0};
   }
   tip = () => {
   var a=parseFloat(this.state.n1);
   var r=a*0.20;
   alert("Tip: " + r);
  }

  render() {
   return (
   <View>
   <Text style={styles.titleTxt}>Tip Calculating</Text>
   
   <TextInput style = {styles.input}
   keyboardType ='numeric'
   placeholder = "Enter Your Bill"
   placeholderTextColor = "gray"
   onChangeText={n1=>this.setState({n1})} />
  
  <View style={styles.container}>
   <TouchableOpacity onPress={this.tip}>
   <Text style = {styles.button}> Calculate for Tip </Text>
   </TouchableOpacity>
   </View>
  
  
   </View>
   )
   }
  }


  class IntCalc extends Component {
    constructor(props){
      {/* props declares 3 states to be managed by the class via text inputs */}
      super(props);
      this.state ={n1:0,n2:0,n3:0};
      }
      
      //* function interest is declared *//
     interest = () => {
      {/* these three vars declared have values equal to the parsed states from the inputs into floats */}
      var a=parseFloat(this.state.n1);
      var b=parseFloat(this.state.n2);
      var c=parseFloat(this.state.n3);

      if(c < 100){
        {/* code that runs if c does not exceed a value of 100 */}
        var d = c/100;
        
        var r=(a*b)*d;
        var e = a + r;

        alert("Interest: " + r + "\nTotal Amount to be Paid/Received: " + e);
      }else{
        alert("Not valid Interest rate.");
      }
      
    
     }
  
    render() {
     return (
     <View>
     <Text style={styles.titleTxt}>Simple Interest Calculating</Text>
     
     <TextInput style = {styles.input}
     keyboardType ='numeric'
     placeholder = "Enter Initial Balance"
     placeholderTextColor = "gray"
     onChangeText={n1=>this.setState({n1})} />

     <TextInput style = {styles.input}
     keyboardType ='numeric'
     placeholder = "Enter Years"
     placeholderTextColor = "gray"
     onChangeText={n2=>this.setState({n2})} />

     <TextInput style = {styles.input}
     keyboardType ='numeric'
     placeholder = "Enter Interest Rate"
     placeholderTextColor = "gray"
     onChangeText={n3=>this.setState({n3})} />



     {/* This TouchableOpacity calls the interest function on press */}
     <View style={styles.container}>
     <TouchableOpacity onPress={this.interest}>
     <Text style = {styles.button}> Calculate Interest </Text>
     </TouchableOpacity>
     </View>
    
    
     </View>
     )
     }
    }









const Stack = createNativeStackNavigator();
function App() {
 return (
 <NavigationContainer>
 <Stack.Navigator initialRouteName="Home">
 <Stack.Screen name="Home" component={Home} />
 <Stack.Screen name="Tip Calculator" component={TipCalc} />
 <Stack.Screen name="Simple Interest Calculator" component={IntCalc} />
 </Stack.Navigator>
 </NavigationContainer>
 );
}
export default App;



const styles = StyleSheet.create({
  container: {
  paddingTop: 100,
  alignItems: 'center',
  justifyContent: 'center',
  },
  input: {
  margin: 15,
  height: 60,
  borderColor: 'green',
  borderWidth: 5,
  fontSize:20,
  textAlign: 'center'
  },
  button: {
  fontSize:30,
  margin: 20,
  backgroundColor: "skyblue",
  width: 250,
 height: 50,
 textAlign:'center'
  },
  titleTxt:{
  color: 'red',
  fontSize:35,
  fontWeight: 'bold',
  textAlign:'center',
  marginBottom: 10
  }
 })