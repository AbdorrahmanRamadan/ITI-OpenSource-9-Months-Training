import {Text, TouchableOpacity, View} from "react-native";

const ButtonDetails = ({text, onPress}) => {
  return (
    <TouchableOpacity onPress={onPress}>
      <View style={{paddingVertical: 10, marginVertical: 5, justifyContent: 'center', alignItems: 'center', backgroundColor: '#008CBA', borderRadius:10}}>
        <Text style={{color: 'white'}}>{text}</Text>
      </View>
    </TouchableOpacity>
  )
}
const ButtonDelete = ({text, onPress}) => {
  return (
    <TouchableOpacity onPress={onPress}>
      <View style={{paddingVertical: 10, marginVertical: 5, justifyContent: 'center', alignItems: 'center', backgroundColor: '#f44336', borderRadius:10}}>
        <Text style={{color: 'white'}}>{text}</Text>
      </View>
    </TouchableOpacity>
  )
}
export {ButtonDetails, ButtonDelete};