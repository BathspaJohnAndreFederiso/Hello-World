import React, { Component } from 'react'
import { View, Text, TextInput, StyleSheet,Button, 
Alert,TouchableOpacity } from 'react-native'



export default class TipCalc extends Component {
constructor(props){
 super(props);
 this.state ={ n1:0,n2:0, n3: 0.15};
 }
 sum = () => {
 var a=parseInt(this.state.n1);
 var b=parseInt(this.state.n2);
 var r=a/0.20;
 alert("Tip: " + r);
}
subtract = () => {
 var a=parseInt(this.state.n1);
 var b=parseInt(this.state.n2);
 var c=parseInt(this.state.n3);
 var r=a*b*c;
 alert("Interest: " + r);
}

 
render() {
 return (
 <View >
 <Text style={styles.submitxt}>Calculator</Text>
 
 <TextInput style = {styles.input}
 keyboardType ='numeric'
 placeholder = "Enter First Number"
 placeholderTextColor = "red"
 onChangeText={n1=>this.setState({n1})} />

 <TextInput style = {styles.input}
 keyboardType ='numeric'
placeholder = "Enter 2nd Number"
 placeholderTextColor = "red"
 onChangeText={n2=>this.setState({n2})} />




<View style={styles.container}>
 <TouchableOpacity onPress={this.sum}>
 <Text style = {styles.button}> + </Text>
 </TouchableOpacity>
 
<TouchableOpacity onPress={this.subtract}>
 <Text style = {styles.button}>
 -
 </Text>
 </TouchableOpacity>
<TouchableOpacity onPress={this.multy}>
 <Text style = {styles.button}>
 *
 </Text>
 </TouchableOpacity>
<TouchableOpacity onPress={this.division}>
 <Text style = {styles.button}>
 /
 </Text>
 </TouchableOpacity>
 </View>
 </View>
 )
 }
}
const styles = StyleSheet.create({
 container: {
 paddingTop: 5,
flexDirection:'row',
justifyContent: 'space-between',
 },
 input: {
 margin: 20,
 height: 60,
 borderColor: 'green',
 borderWidth: 5,
 fontSize:30,
 },
 button: {
 borderColor: 'green',
 fontSize:30,
 margin: 20,
 borderRadius: 6,
backgroundColor: "red",
 width: 50,
height: 50,
textAlign:'center'
 },
 submitxt:{
 color: 'red',
 fontSize:20,
 textAlign:'center'
 }
})