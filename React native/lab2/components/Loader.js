import {ActivityIndicator, View} from "react-native";

const Loader = () => {
  return (

    <View style={{flex: 4, alignItems: 'center', justifyContent: 'center'}}>
      <ActivityIndicator size={"large"} />
    </View>
  )
}
export default Loader;
