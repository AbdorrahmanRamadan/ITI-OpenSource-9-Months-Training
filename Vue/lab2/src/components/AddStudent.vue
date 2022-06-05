<template>
  <div>
    <form class="w-50 m-auto mt-3">
      <div class="mb-3">
        <label>First Name</label>
        <input type="text" class="form-control" v-model="formValues.first_name"/>
      </div>
      <div class="mb-3">
        <label>Last Name</label>
        <input type="text" class="form-control" v-model="formValues.last_name"/>
      </div>
      <div class="mb-3">
        <label>Email</label>
        <input type="email" class="form-control" v-model="formValues.email"/>
      </div>
      <div class="mb-3">
        <label>Gender</label>
        <div class="form-check">
          <input class="form-check-input" type="radio" name="gender" id="flexRadioDefault1" v-model="formValues.gender" v-bind:value="'Female'">
          <label class="form-check-label" for="flexRadioDefault1">
            Female
          </label>
        </div>
        <div class="form-check">
          <input class="form-check-input" type="radio" name="gender" id="flexRadioDefault2" v-model="formValues.gender" v-bind:value="'Male'" checked>
          <label class="form-check-label" for="flexRadioDefault2">
            Male
          </label>
        </div>
      </div>
      <div class="mb-3 text-center">
        <button class="btn btn-primary" @click.prevent="addStudent">Add Student</button>
      </div>
    </form>
  </div>
</template>

<script>
import axios from "axios";

export default {
  name: "AddStudent",
  data(){
    return{
        formValues:{
          first_name:"",
          last_name:"",
          email:"",
          gender:"male"
      }
    }
  },
  methods:{
    addStudent(){
      axios.post("http://localhost:5500/students",this.formValues).then(()=>{
        this.$router.push('/students')
      })
    }
  }
}
</script>

<style scoped>

</style>