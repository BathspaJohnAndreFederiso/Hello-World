import React, { Component, } from 'react'
import { View, Text, Pressable, Modal,
Alert,TouchableOpacity } from 'react-native' // imports some stuff from react and react-native
import {styles} from './Styles' // imports the styles const from Styles.js



export default class App extends Component { // creates and exports class App with components
constructor(props){ 
 super(props);
 this.state ={ n1:0,n2:0 }; // creates two states n1 and n2
 }
 sum = () => { // sum function with no passed in values
 var a=parseInt(this.state.n1); // creates variable a with the value of the state of n1 run through parseInt
 var b=parseInt(this.state.n2);  // creates variable b with the value of the state of n2 run through parseInt

 if(a == 1){ // 1 = liquid, 2 = solid, 3 = gas, if statement runs if a is equal to 1
   if(b == 2){ // nested if statement that runs if b is equal to 2
    var r="Freezing"; // assigns to variable r string "Freezing"
   }else if(b == 3){ // nested else if that runs if b is equal to 3
    var r="Evaporation"; // assigns to r string "Evaporation"
   }else if (b == 1){ // else if if both a and b have the same value
    var r ="No Transition/Not Valid"  // assigns to r an approriate string message
   }
 }
 else if(a == 2){ // if statement if a has the value of 2
  if(b == 1){ // you can see the varying messages since now 2 (solid) is assigned to a (and a is the original state)
    var r="Melting";
   }else if(b == 3){
    var r="Sublimation";
   }else if (b == 2){
    var r ="No Transition/Not Valid"  // same value for both a and b return the same message
   }
 }
 else if(a == 3){ // ditto
  if(b == 1){
    var r="Condensation";
   }else if(b == 2){
    var r="Deposition";
   }else if (b ==3){
    var r ="No Transition/Not Valid" 
   }
 }
 else if(a == 0 || b == 0){
   var r ="You have not chosen for both states yet."
 }


 alert(r); // creates alert with r value passed in
}


state = {
  modalVisible: false
};

setModalVisible = (visible) => {
  this.setState({ modalVisible: visible });
}



render() {

  const { modalVisible } = this.state;
  

 return (



 <View>
   {/*declares some Texts and Views with the appropriate styles assigned to them, this line has the title of this section */}
 <Text style={styles.submitxt}>Matter State Transitions</Text>   
 
 <Text style={styles.labeltxt}>Original State</Text>  
 <View style={styles.container}>
 <TouchableOpacity  onPress={n1=>this.setState({n1 : '1'})}>
 <Text style = {styles.button}> Liquid </Text>  
 </TouchableOpacity> 
 
<TouchableOpacity onPress={n1=>this.setState({n1 : "2"})}> 
 <Text style = {styles.button}>
 Solid 
 </Text>
 </TouchableOpacity>

<TouchableOpacity onPress={n1=>this.setState({n1 : "3"})}> 
 <Text style = {styles.button}>
 Gas
 </Text>
 </TouchableOpacity>
 </View>


<Text style={styles.labeltxt}>Next State</Text> 
  
<View style={styles.container}>
 <TouchableOpacity onPress={n2=>this.setState({n2 : "1"})}> 
 <Text style = {styles.button}> Liquid </Text> 
 </TouchableOpacity>
 
<TouchableOpacity onPress={n2=>this.setState({n2 : "2"})}>
 <Text style = {styles.button}>
 Solid
 </Text>
 </TouchableOpacity>

<TouchableOpacity onPress={n2=>this.setState({n2 : "3"})}>
 <Text style = {styles.button}>
 Gas
 </Text>
 </TouchableOpacity>
 </View>





<View style={styles.container1}>
 <TouchableOpacity onPress={this.sum}>  
 <Text style = {styles.button1}> TRANSITION </Text> 
 </TouchableOpacity>
 </View>


        <Modal  
          animationType="slide"
          transparent={true}
          visible={modalVisible}
          
          onRequestClose={() => {
            Alert.alert("Modal has been closed."); 
            this.setModalVisible(!modalVisible);
          }}
        >
          <View style={styles.centeredView}>
            <View style={styles.modView}>
              <Text style={styles.modText}>This is the States of Matter Calculator!</Text>

              <Text style={styles.modText}>Select two states from the two sections...</Text>  

              <Text style={styles.modText}>And click on Transition to find the transition between the states you selected.</Text>

              <Pressable 
                style={[styles.button, styles.buttonClose]}
                onPress={() => this.setModalVisible(!modalVisible)}
              >
                <Text style={styles.textStyle}>Got It</Text>
              </Pressable>
            </View>
          </View>
        </Modal>

        





 </View>
 )


 }
}


