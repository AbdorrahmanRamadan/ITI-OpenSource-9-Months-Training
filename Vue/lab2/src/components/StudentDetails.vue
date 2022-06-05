<template>
    <div class="container">
        <div class="card w-50 m-auto mt-3">
            <div class="card-header">
                Student Details
            </div>
            <div class="card-body">
                <p>Student ID : {{student.id}}</p>
                <p>Student Name : {{student.first_name}} {{student.last_name}}</p>
                <p>Student Email : {{student.email}}</p>
                <p>Student Gender : {{student.gender}}</p>
            </div>
        </div>
    </div>
</template>

<script>
import axios from 'axios'
    export default {
        name: "PostDetails",
        data(){
            return{
                studentID:0,
                student:{},
            }
        },
        created(){
            this.getStudentData()
        },
        methods:{
            async getStudentData(){
                this.studentID = this.$route.params.id
                await axios.get(`http://localhost:5500/students/${this.studentID}`)
                .then((response)=>{
                    this.student = response.data
                    console.log(this.student)
                    })
            }
        }
    }
</script>

<style scoped>

</style>