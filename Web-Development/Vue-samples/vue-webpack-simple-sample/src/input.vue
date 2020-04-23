<template>
    <div>
        <input type="text" :value="msg" @input="update">
        <p>{{message}}</p>
    </div>
</template>

<script>
export default {
    props: ['msg'],
    data(){
        return {
            message:''
        }
    },
    methods:{
        update(event){
            this.message=event.target.value;
            this.$emit('updateYasta',this.message);
        }
    }
}
</script>