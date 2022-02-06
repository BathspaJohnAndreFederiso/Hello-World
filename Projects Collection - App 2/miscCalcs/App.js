import * as React from 'react';
import {Component} from 'react';
import { Button, View, Text, Image, TextInput, TouchableOpacity, StyleSheet, Modal, Pressable } from 'react-native';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack'; // imports some navigation features from downloaded react-navigation




function Home({ navigation }) {

  {/* This is the home function, there are buttons that call the navigation from the react navigation package to let the user go to different pages  */}

 return (
 <View  style={{flex: 1, alignItems: 'center', justifyContent: 'space-around', backgroundColor: 'gray'}}>
 <Text style={styles.titleTxt}>Business Calculator</Text>
 <Image source = {require("./assets/logo.png")} style ={{width: "20%", height: "20%"}}/>
  
  <Button
   title="Calculate for Tip"
   onPress={() => navigation.navigate('Tip Calculator')}
  />
   
  {/* This button tells the navigation to call the Stack.Screen 'Tip Calculator' on press */}

  <Button 
   title="Calculate for Simple Interest"
   onPress={() => navigation.navigate('Simple Interest Calculator')}
  />
  
  {/* ditto but for 'Simple Interest Calculator' */}

 </View>

 );
}



  class TipCalc extends Component {
  constructor(props){
   super(props);

   {/* declares only one state */}

   this.state ={ n1:0};
   }

   //* function tip is created with no passed in arguments*//

   tip = () => {
     {/* declares var a which parses the value of n1 into float */}
   var a=parseFloat(this.state.n1);
   {/* declares var r which is a multiplied by 0.20*/}
   var r=a*0.20;
   {/*uses alert system to return the value of r, which is the tip amount*/}
   alert("Tip: " + r);
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
   <Text style={styles.titleTxt}>Tip Calculating</Text>
   {/* textinput uses the n1 state to grab any entered values */}
   <TextInput style = {styles.input}
   keyboardType ='numeric'
   placeholder = "Enter Your Bill"
   placeholderTextColor = "gray"
   onChangeText={n1=>this.setState({n1})} />
  
   {/*button calls the tip function */}
  <View style={styles.container}>
   <TouchableOpacity onPress={this.tip}>
   <Text style = {styles.button1}> Calculate for Tip </Text>
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
          <View style={styles.centeredModalView}>
            <View style={styles.modalView}>
              <Text style={styles.modalTxt}>This is the Tip Calculating Page </Text>
              <Text style={styles.modalTxt}>Enter your bill paid </Text>

              <Pressable 
                style={[styles.modalButton, styles.modalButtonClose]}
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

      if(c <= 100 || c > 0){
        {/* code that runs if c does not exceed a value of 100 */}
        var d = c/100;
        {/* creates new variable d and assigned to it the value of c divided by 100 */}
        var r=(a*b)*d;
        var e = a + r;
        {/* r is used to return the interest amount, e is used to return the interest + loan value*/}
        alert("Interest: " + r + "\nTotal Amount to be Paid/Received: " + e);
      }else{
        alert("Not a valid Interest rate entered. Enter another one (Below 100 and above 0)");
      }
      
    
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
      {/* These buttons assign to the states the values of the textInputs*/}
     <TextInput style = {styles.input}
     keyboardType ='numeric'
     placeholder = "Enter Interest Rate"
     placeholderTextColor = "gray"
     onChangeText={n3=>this.setState({n3})} />



     {/* This TouchableOpacity calls the "interest" function on press */}
     <View style={styles.container}>
     <TouchableOpacity onPress={this.interest}>
     <Text style = {styles.button1}> Calculate Interest </Text>
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
          <View style={styles.centeredModalView}>
            <View style={styles.modalView}>
              <Text style={styles.modalTxt}>This is the Simple Interest Calculating Page </Text>
              <Text style={styles.modalTxt}>Enter your initial value, years, and the rate of interest </Text>

              <Pressable 
                style={[styles.modalButton, styles.modalButtonClose]}
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








 // creates const Stack, used to create a stack navigator from react-navigation/native stack
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
// the initial route (read: upon launching the app) set is Home, which leads to the other two pages TipCalc and IntCalc


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
  fontSize:30,
  textAlign: 'center'
  },
  button1: {
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
  },
  modalTxt:{
    marginBottom: 5,
    textAlign: "center"
    },
    centeredModalView: {
      flex: 1,
      justifyContent: "center",
      alignItems: "center",
      marginTop: 40
    },
    modalView: {
      margin: 20,
      backgroundColor: "white",
      borderRadius: 20,
      padding: 15,
      alignItems: "center",
      shadowColor: "#000",
      shadowOffset: {
        width: 0,
        height: 2
      },
      shadowOpacity: 0.20,
      shadowRadius: 4,
      elevation: 5
    },
    modalButton: {
      borderRadius: 20,
      padding: 10,
      elevation: 2,
      textAlign:'center'
      
    },
    modalButtonClose: {
      backgroundColor: "#2196F3",
    },
    textStyle: {
      color: "white",
      fontWeight: "bold",
      textAlign: "center"
    },
    modalText: {
      marginBottom: 15,
      textAlign: "center"
    },
 })