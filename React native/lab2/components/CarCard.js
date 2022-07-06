import {Image, Text, TouchableOpacity, View} from "react-native";
import {useNavigation} from "@react-navigation/native";
import {ButtonDetails, ButtonDelete} from "./Button";
import CARS_DATA from "../CARS_DATA";
const CarCard = ({car}) => {
  const navigation = useNavigation();
  return (
    <View style={{
      margin: 10,
      padding: 10,
      borderRadius: 20,
      borderWidth: 2,
    }}>
      <View style={{
        flexDirection: 'row',
        zIndex: 2,
        width: '100%',
        justifyContent: 'space-between',
        position: 'absolute',
        top: 10,
        left: 10,
        padding: 10,
        alignItems: 'flex-start',
      }}>

      <Image source={{uri: car.brand}} style={{width: 40, height: 40}} />
        <View style={{
          backgroundColor: '#008CBA',
          paddingVertical: 3,
          paddingHorizontal: 10,
          borderRadius: 5,
        }}>
          <Text style={{color: 'white',}}>{car.model}</Text>
        </View>
      </View>
      <Image source={{uri: car.image}} style={{width: '100%', height: 200, marginBottom: 5,}} />
      <Text style={{fontSize: 20, fontWeight: 'bold'}}>{car.name}</Text>
      <ButtonDetails onPress={() => navigation.navigate("CarDetails", {car})} text={'View Details'}  />
      <ButtonDelete onPress={()=>{CARS_DATA.map((c, index)=>{if(c.id === car.id){CARS_DATA.shift(index, 1)}})}} text={'Delete'}/>
    </View>
  );
};
export default CarCard;
