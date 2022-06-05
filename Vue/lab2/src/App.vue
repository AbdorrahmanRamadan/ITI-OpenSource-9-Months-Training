<template>
  <navigationBar></navigationBar>
  <router-view></router-view>
</template>

<script>

import NavigationBar from "@/components/NavigationBar";
export default {
  name: 'App',
  components: {
    NavigationBar

  }
}
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
