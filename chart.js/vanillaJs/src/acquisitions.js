import Chart from 'chart.js/auto'



const showChart = async () => {

    const chartData = [
        {year: 2010, count:10},
        {year: 2011, count:20},
        {year: 2012, count:15},
        {year: 2013, count:25},
        {year: 2014, count:22},
        {year: 2015, count:30},
        {year: 2016, count:26},
        {year: 2017, count:28},
    ];
    const ctx = document.getElementById('acquisitions');

    new Chart(ctx, {
        type: 'bar',
        data: {
            labels: chartData.map(section => section.year),
            datasets: [
                {
                label: "Acquisitions per year",
                data: chartData.map(section => section.count)
                }
            ] 
        }
    })

};

showChart();