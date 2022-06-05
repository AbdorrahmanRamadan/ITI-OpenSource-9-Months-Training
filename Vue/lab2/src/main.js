import { createApp } from 'vue'
import App from './App.vue'
import {createRouter,createWebHistory} from "vue-router";
import AllStudents from "@/components/AllStudents";
import AddStudent from "@/components/AddStudent";
import StudentDetails from "@/components/StudentDetails";
import EditStudent from "@/components/EditStudent";

const routes =[
    {
        path:'/students',
        component:AllStudents
    },
    {
        path:'/student/add',
        component:AddStudent
    },
    {
        path:'/student/edit/:id',
        component:EditStudent
    },
    {
        path:'/student/:id',
        component:StudentDetails
    }
]
const router = createRouter({
    history:createWebHistory(),
    routes
})
createApp(App).use(router).mount('#app')
