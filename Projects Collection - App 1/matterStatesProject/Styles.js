import React, { Component } from 'react'
import {StyleSheet } from 'react-native'


 //export default styles;

 export const styles = StyleSheet.create({
    container1: {

        paddingTop: 5,
       flexDirection:'row',
       justifyContent: 'center',
        },
        input: {
        margin: 20,
        height: 60,
        borderColor: 'green',
        borderWidth: 5,
        fontSize:30,
        },
        button1: {
         borderColor: 'green',
         fontSize:30,
         margin: 20,
         borderRadius: 6,
        backgroundColor: "skyblue",
         width: 200,
        height: 50,
        textAlign:'center'
         },
         submitxt:{
         color: 'red',
         fontSize:40,
         textAlign:'center'
         },
         labeltxt:{
           
           fontSize:17,
           textAlign:'center'
           },
       
         modalText:{
         marginBottom: 15,
         textAlign: "center"
         },
         centeredView: {
           flex: 1,
           justifyContent: "center",
           alignItems: "center",
           marginTop: 22
         },
         modalView: {
           margin: 20,
           backgroundColor: "white",
           borderRadius: 20,
           padding: 35,
           alignItems: "center",
           shadowColor: "#000",
           shadowOffset: {
             width: 0,
             height: 2
           },
           shadowOpacity: 0.25,
           shadowRadius: 4,
           elevation: 5
         },
         button: {
           borderRadius: 20,
           padding: 10,
           elevation: 2,
           
           
         },
         buttonOpen: {
           backgroundColor: "#F194FF",
         },
         buttonClose: {
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
         container: {
          paddingTop: 5,
         flexDirection:'row',
         justifyContent: 'space-between',
          },
          
       
 });
