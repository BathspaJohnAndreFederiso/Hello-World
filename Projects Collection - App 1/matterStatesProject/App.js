import React, { Component, } from 'react'
import { View, Text, Pressable, Modal,
Alert,TouchableOpacity } from 'react-native'
import {styles} from './Styles'



export default class App extends Component {
constructor(props){
 super(props);
 this.state ={ n1:0,n2:0 };
 }
 sum = () => {
 var a=parseInt(this.state.n1);
 var b=parseInt(this.state.n2); 

 if(a == 1){ // 1 = liquid, 2 = solid, 3 = gas
   if(b == 2){
    var r="Freezing";
   }else if(b == 3){
    var r="Evaporation";
   }else if (b == 1){
    var r ="No Transition/Not Valid" 
   }
 }
 else if(a == 2){
  if(b == 1){
    var r="Melting";
   }else if(b == 3){
    var r="Sublimation";
   }else if (b == 2){
    var r ="No Transition/Not Valid" 
   }
 }
 else if(a == 3){
  if(b == 1){
    var r="Condensation";
   }else if(b == 2){
    var r="Deposition";
   }else if (b ==3){
    var r ="No Transition/Not Valid" 
   }
 }


 alert(r);
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
 <Text style={styles.submitxt}>States of Matter</Text> 
 
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
            <View style={styles.modalView}>
              <Text style={styles.modalText}>This is the States of Matter Calculator!</Text>

              <Text style={styles.modalText}>Select two states from the first two rows...</Text>

              <Text style={styles.modalText}>And click on Transition to find the transition between the states you selected.</Text>

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


